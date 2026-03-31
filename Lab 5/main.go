package main

import ("fmt"; "net"; "os")

func main() {
	version := os.Getenv("VERSION")
	hostname, _ := os.Hostname()
	ip := "Brak IP"

	// Pobranie lokalnego IP
	addrs, _ := net.InterfaceAddrs()
	for _, a := range addrs {
		if ipnet, ok := a.(*net.IPNet); ok && !ipnet.IP.IsLoopback() && ipnet.IP.To4() != nil {
			ip = ipnet.IP.String()
			break
		}
	}

	// Wygenerowanie pliku index.html
	html := fmt.Sprintf(
		"<h1>Aplikacja Webowa - Lab 5</h1><p>Adres IP: %s</p><p>Hostname: %s</p><p>Wersja: %s</p>",
		ip, hostname, version,
	)
	os.WriteFile("index.html", []byte(html), 0644)
}
