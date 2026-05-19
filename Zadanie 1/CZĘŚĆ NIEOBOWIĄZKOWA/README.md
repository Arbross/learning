## 1. Aplikacja pogodowa

Projekt **weather-app** to minimalistyczna aplikacja webowa napisana w języku **Go**, która wyświetla aktualne dane pogodowe z serwisu **Open-Meteo** dla wybranych miast w Polsce, Niemczech, Francji, Wielkiej Brytanii, USA i Japonii.

## 2. Struktura projektu

```
Dockerfile           # Definicja wieloetapowego obrazu
go.mod               # Moduł Go
main.go              # Kod źródłowy serwera HTTP
public/
  index.html       # Strona frontendowa (embed w Go)
images/              # Zrzuty ekranu / zasoby graficzne
README.md
```

## 3. Funkcjonalności aplikacji

- **Strona główna (`/`)** — zwraca osadzony plik `index.html`.
- **Pogoda (`/weather?country=<kraj>&city=<miasto>`)** — zwraca dane pogodowe w formacie JSON (temperatura, wilgotność, wiatr, ciśnienie, opady, opis pogody, strefa czasowa).
- **Lokalizacje (`/locations`)** — lista dostępnych krajów i miast.
- **Healthcheck (`/health`)** — punkt kontrolny zdrowia aplikacji, wykorzystywany w `HEALTHCHECK` Dockerfile.

Dostępne lokalizacje:
- **Poland**: Warsaw, Lublin, Gdansk
- **Germany**: Berlin, Munich, Hamburg
- **France**: Paris, Lyon, Marseille
- **United Kingdom**: London, Manchester, Edinburgh
- **USA**: New York, Los Angeles, Chicago
- **Japan**: Tokyo, Osaka, Kyoto

## 4. Wymagania przed budową

1. Zainstalowany i uruchomiony **Docker Desktop** lub Docker Engine z włączonym BuildKit.
2. Zainstalowany i skonfigurowany **Docker Buildx**.
3. Dane logowania do rejestru (np. Docker Hub), jeśli planujesz wysłać obraz (`--push`).
4. (Opcjonalnie) Plik `github_token.txt` w katalogu głównym, jeśli chcesz wykorzystać sekret podczas budowania.

## 5. Instrukcja budowania (Część Nieobowiązkowa)

Poniższe kroki realizują nowoczesny pipeline budowania obrazu Docker z wykorzystaniem Buildx.

### 5.1. Utworzenie i aktywacja buildera

```bash
docker buildx create --name my-cloud-builder --driver docker-container --use
docker buildx inspect --bootstrap
```

> Builder `my-cloud-builder` działa w kontenerze, co umożliwia budowanie dla wielu architektur równolegle.

### 5.2. Budowanie obrazu multi-platform i push do rejestru

```bash
docker buildx build \
  --builder my-cloud-builder \
  --platform linux/amd64,linux/arm64 \
  --secret id=github_token,src=github_token.txt \
  -t arbross/weather-app:latest \
  --cache-to type=registry,ref=arbross/weather-app:buildcache,mode=max \
  --cache-from type=registry,ref=arbross/weather-app:buildcache \
  --push .
```

**Wyjaśnienie flag:**
- `--platform linux/amd64,linux/arm64` — budowanie obrazów dla dwóch architektur.
- `--secret id=github_token,src=github_token.txt` — bezpieczne przekazanie sekretu do buildu bez zapisywania go w warstwach obrazu.
- `-t arbross/weather-app:latest` — tag obrazu w rejestrze Docker Hub (zmień `arbross` na swoją nazwę użytkownika).
- `--cache-to / --cache-from` — wykorzystanie rejestru jako zewnętrznego cache'u dla przyspieszenia kolejnych budowań.
- `--push` — automatyczne wypchnięcie gotowego obrazu do rejestru.

### 5.3. Weryfikacja obrazu w rejestrze

```bash
docker buildx imagetools inspect arbross/weather-app:latest
```

Polecenie wyświetli metadane obrazu, w tym listę wspieranych platform (manifest list).

### 5.4. Skanowanie podatności (Docker Scout)

```bash
docker scout cves arbross/weather-app:latest
```

Narzędzie przeanalizuje warstwy obrazu i wskaże potencjalne luki bezpieczeństwa (CVE).

## Lokalne uruchomienie obrazu

Jeśli chcesz uruchomić gotowy obraz lokalnie (dla architektury hosta):

```bash
docker run -d \
  --name weather-app \
  -p 3000:3000 \
  -e AUTHOR="Twoje Imię" \
  -e PORT=3000 \
  arbross/weather-app:latest
```

Aplikacja będzie dostępna pod adresem: [http://localhost:3000](http://localhost:3000)

Punkt zdrowia: [http://localhost:3000/health](http://localhost:3000/health)

## Szczegóły Dockerfile

Obraz składa się z dwóch etapów:

1. **Etap `builder`:**
   - Bazuje na `golang:1.26.3-alpine` (platforma hosta dla szybszej kompilacji krzyżowej).
   - Instaluje `upx` i `git`.
   - Wykorzystuje `RUN --mount=type=secret` do załadowania tokena bez pozostawiania śladów w historii obrazu.
   - Używa `RUN --mount=type=cache` dla przyspieszenia `go mod download` i kompilacji.
   - Kompiluje statyczną binarkę (`CGO_ENABLED=0`, `-ldflags="-s -w"`).
   - Kompresuje wynikowy plik za pomocą `upx --best --lzma`.

2. **Etap finalny (`scratch`):**
   - Całkowicie pusty obraz bazowy — brak zbędnych narzędzi i bibliotek.
   - Zawiera wyłącznie skompresowany plik wykonywalny ze stadium build.
   - Eksponuje port **3000**.
   - Ustawia zmienne środowiskowe `AUTHOR` i `PORT`.
   - Definiuje `HEALTHCHECK` odpytujący aplikację co 30 sekund.
   - Zawiera metadane OCI (autor, opis, wersja).

## Zmienne środowiskowe

| Zmienna | Domyślnie | Opis |
|---------|-----------|------|
| `AUTHOR` | `Viktor Pavlovskyi` | Autor wyświetlany w logach startowych |
| `PORT` | `3000` | Port, na którym nasłuchuje serwer |

## Zrzuty ekranu

| Opis | Podgląd |
|------|---------|
| Budowanie obrazu (`docker buildx build`) | ![docker-build](images/docker-build.png) |
| Weryfikacja manifestu obrazu multi-platform | ![manifest](images/manifest.png) |
| Skanowanie podatności (`docker scout cves`) | ![docker-scout](images/docker-scout.png) |
| Konfiguracja sekretu w Docker Hub | ![secret-docker-hub](images/secret-docker-hub.png) |
| Ustawienie zmiennych środowiskowych | ![env_setup](images/env_setup.png) |
| DockerHub | ![docker_hub_web](images/docker_hub_web.png) |

## Docker Hub

[Adres URL na Docker Hub z obrazem](https://hub.docker.com/r/arbross/weather-app)
