package main

import ("fmt"; "net"; "net/http"; "os")

func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		version := os.Getenv("VERSION")
		hostname, _ := os.Hostname()

		ip := "Brak IP"
		addrs, _ := net.InterfaceAddrs()
		for _, a := range addrs {
			if ipnet, ok := a.(*net.IPNet); ok && !ipnet.IP.IsLoopback() && ipnet.IP.To4() != nil {
				ip = ipnet.IP.String()
				break
			}
		}

		fmt.Fprintf(w, "<h2>Serwer Go + Nginx Proxy</h2><p>Aktualne IP: %s</p><p>Hostname: %s</p><p>Wersja: %s</p>", 
			ip, hostname, version)
	})

	// Start serwera na porcie 8088
	http.ListenAndServe(":8088", nil)
}
