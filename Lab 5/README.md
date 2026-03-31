# Laboratorium 5
W tym laboratorium wykonano zadanie z Reverse Proxy, gdzie serwer Nginx pośredniczy w komunikacji z aplikacją napisaną w języku Go.

### Struktura projektu
Etap 1: Wykorzystanie obrazu bazowego z obsługą Go (Alpine) do skompilowania kodu źródłowego serwera aplikacji.

Etap 2: Wykorzystanie obrazu Nginx jako serwera pośredniczącego (Reverse Proxy).

Dane: Dynamiczne pobieranie adresu IP, nazwy hosta (hostname) oraz wersji aplikacji przy każdym zapytaniu HTTP.

Healthcheck: Implementacja mechanizmu sprawdzania poprawności działania kontenera przy użyciu narzędzia curl.

### Reverse Proxy
Adres 172.17.0.1 to zazwyczaj brama sieci Docker. Adres 172.17.0.2 to zazwyczaj pierwszy uruchomiony kontener w danej sieci, natomiast adres 172.17.0.3 to aktualnie działający kontener. Wyświetlenie tego adresu potwierdza, że aplikacja Go poprawnie odczytuje interfejs sieciowy działającego kontenera, a Nginx prawidłowo przekazuje do niej ruch.

### Instrukcja Uruchomienia
Budowanie obrazu
Aby zbudować obraz i przekazać wersję aplikacji jako argument, należy wykonać:

 - docker build --build-arg VERSION=1.5.0-proxy -t lab5-nginx-proxy .
 - docker run -d -p 8080:80 --name moj-serwer-proxy lab5-nginx-proxy

Po uruchomieniu można zweryfikować status kontenera oraz działanie usługi:

 - docker ps
 - curl http://localhost:8080

### Struktura plików
 - Dockerfile # Instrukcje budowania obrazu
 - main.go    # Serwer aplikacji w języku Go
 - nginx.conf # Konfiguracja Nginx Reverse Proxy
 - README.md  # Dokumentacja projektu
 - images/    # Dokumentacja graficzna
    docker-setup.jpg
    dockerfile.jpg
    golang-script.jpg
    nginx-conf.jpg