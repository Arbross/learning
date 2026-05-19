package main

import (
	"crypto/tls"
	"embed"
	"encoding/json"
	"fmt"
	"net/http"
	"time"
	"os"
)

//go:embed public/index.html
var html embed.FS

var client = &http.Client{
	Timeout: 8 * time.Second,
	Transport: &http.Transport{
		TLSClientConfig: &tls.Config{InsecureSkipVerify: true},
	},
}

var locations = map[string]map[string][2]float64{
	"Poland":         {"Warsaw": {52.23, 21.01}, "Lublin": {51.25, 22.57}, "Gdansk": {54.35, 18.65}},
	"Germany":        {"Berlin": {52.52, 13.40}, "Munich": {48.14, 11.58}, "Hamburg": {53.58, 10.02}},
	"France":         {"Paris": {48.86, 2.35}, "Lyon": {45.76, 4.84}, "Marseille": {43.30, 5.37}},
	"United Kingdom": {"London": {51.51, -0.13}, "Manchester": {53.48, -2.24}, "Edinburgh": {55.95, -3.19}},
	"USA":            {"New York": {40.71, -74.01}, "Los Angeles": {34.05, -118.24}, "Chicago": {41.88, -87.63}},
	"Japan":          {"Tokyo": {35.68, 139.65}, "Osaka": {34.69, 135.50}, "Kyoto": {35.01, 135.77}},
}

type OpenMeteoResponse struct {
	Timezone string `json:"timezone"`
	Current  struct {
		Time                string  `json:"time"`
		Temperature2m       float64 `json:"temperature_2m"`
		ApparentTemperature float64 `json:"apparent_temperature"`
		RelativeHumidity2m  int     `json:"relative_humidity_2m"`
		Precipitation       float64 `json:"precipitation"`
		WeatherCode         int     `json:"weather_code"`
		WindSpeed10m        float64 `json:"wind_speed_10m"`
		SurfacePressure     float64 `json:"surface_pressure"`
	} `json:"current"`
}

type FrontendResponse struct {
	Temperature   float64 `json:"temperature"`
	FeelsLike     float64 `json:"feelsLike"`
	Humidity      int     `json:"humidity"`
	WindSpeed     float64 `json:"windSpeed"`
	Precipitation float64 `json:"precipitation"`
	Pressure      float64 `json:"pressure"`
	WeatherCode   int     `json:"weatherCode"`
	Condition     string  `json:"condition"`
	Time          string  `json:"time"`
	Timezone      string  `json:"timezone"`
}

func getWeatherCondition(code int) string {
	switch {
	case code == 0:
		return "Clear Sky"
	case code >= 1 && code <= 3:
		return "Partly Cloudy"
	case code == 45 || code == 48:
		return "Foggy"
	case code >= 51 && code <= 55:
		return "Drizzle"
	case code >= 61 && code <= 65:
		return "Rainy"
	case code >= 71 && code <= 75:
		return "Snowy"
	case code >= 80 && code <= 82:
		return "Rain Showers"
	case code >= 85 && code <= 86:
		return "Snow Showers"
	case code >= 95:
		return "Thunderstorm"
	default:
		return "Unknown"
	}
}

func jsonErr(w http.ResponseWriter, msg string, code int) {
	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(code)
	_ = json.NewEncoder(w).Encode(map[string]string{"error": msg})
}

func main() {
	author := os.Getenv("AUTHOR")
	port := os.Getenv("PORT")

	if author == "" {
		author = "Viktor Pavlovskyi"
	}
	if port == "" {
		port = "3000"
	}

	currentTime := time.Now().Format(time.RFC1123)
	fmt.Printf("Startup Date: %s\n", currentTime)
	fmt.Printf("Author: %s\n", author)
	fmt.Printf("Listening on TCP port: %s\n", port)

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		data, err := html.ReadFile("public/index.html")
		if err != nil {
			http.Error(w, "HTML template not found", http.StatusInternalServerError)
			return
		}
		w.Header().Set("Content-Type", "text/html; charset=utf-8")
		_, _ = w.Write(data)
	})

	http.HandleFunc("/health", func(w http.ResponseWriter, r *http.Request) {
		w.Header().Set("Content-Type", "application/json")
		_, _ = w.Write([]byte(`{"status":"ok"}`))
	})

	http.HandleFunc("/locations", func(w http.ResponseWriter, r *http.Request) {
		w.Header().Set("Content-Type", "application/json")
		_ = json.NewEncoder(w).Encode(locations)
	})

	http.HandleFunc("/weather", func(w http.ResponseWriter, r *http.Request) {
		cities, countryExists := locations[r.URL.Query().Get("country")]
		if !countryExists {
			jsonErr(w, "invalid country provided", http.StatusBadRequest)
			return
		}

		coords, cityExists := cities[r.URL.Query().Get("city")]
		if !cityExists {
			jsonErr(w, "invalid city provided", http.StatusBadRequest)
			return
		}

		apiURL := fmt.Sprintf(
			"https://api.open-meteo.com/v1/forecast?latitude=%f&longitude=%f&current=temperature_2m,apparent_temperature,relative_humidity_2m,precipitation,weather_code,wind_speed_10m,surface_pressure&wind_speed_unit=kmh&timezone=auto",
			coords[0], coords[1],
		)

		resp, err := client.Get(apiURL)
		if err != nil {
			jsonErr(w, "failed to reach weather service", http.StatusInternalServerError)
			return
		}
		defer resp.Body.Close()

		if resp.StatusCode != http.StatusOK {
			jsonErr(w, "external weather service returned an error", resp.StatusCode)
			return
		}

		var apiData OpenMeteoResponse
		if err := json.NewDecoder(resp.Body).Decode(&apiData); err != nil {
			jsonErr(w, "failed to process weather data payload", http.StatusInternalServerError)
			return
		}

		w.Header().Set("Content-Type", "application/json")
		_ = json.NewEncoder(w).Encode(FrontendResponse{
			Temperature:   apiData.Current.Temperature2m,
			FeelsLike:     apiData.Current.ApparentTemperature,
			Humidity:      apiData.Current.RelativeHumidity2m,
			WindSpeed:     apiData.Current.WindSpeed10m,
			Precipitation: apiData.Current.Precipitation,
			Pressure:      apiData.Current.SurfacePressure,
			WeatherCode:   apiData.Current.WeatherCode,
			Condition:     getWeatherCondition(apiData.Current.WeatherCode),
			Time:          apiData.Current.Time,
			Timezone:      apiData.Timezone,
		})
	})

	_ = http.ListenAndServe(":3000", nil)
}
