## Laboratorium 5
Aplikacja wykorzystuje język Go do generowania dynamicznych danych systemowych, które są następnie serwowane przez serwer Nginx.

### Wymagania Projektowe
Etap 1: Wykorzystanie obrazu bazowego z obsługą Go (na bazie Alpine) do wygenerowania pliku index.html.

Dane: Pobranie adresu IP, nazwy hosta (hostname) oraz wersji aplikacji przekazanej przez ARG.

Etap 2: Wykorzystanie obrazu Nginx do serwowania wygenerowanej strony.

Healthcheck: Implementacja mechanizmu sprawdzania poprawności działania kontenera.

## Instrukcja Uruchomienia

### Budowanie obrazu
Podczas budowy należy przekazać argument VERSION, aby zdefiniować wersję aplikacji:

 - docker build --build-arg VERSION=1.0.0 -t lab5-nginx-go .
 - docker run -d -p 8080:80 --name server lab5-nginx-go

Weryfikacja: Poprawność działania można sprawdzić za pomocą komendy docker ps (status Health) lub bezpośrednio w przeglądarce:

Adres lokalny: http://localhost:8080

### Struktura plików:

- Dockerfile # Instrukcje budowania obrazu
- main.go    # Skrypt generujący metadane w Go
- README.md  # Dokumentacja (ten plik)
- images/    # Folder z dokumentacją graficzną
    docker-setup.jpg
    dockerfile.jpg
    golang-script.jpg
    web-link.jpg
