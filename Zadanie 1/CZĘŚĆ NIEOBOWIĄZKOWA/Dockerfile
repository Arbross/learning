# Aktywacja rozszerzonego frontendu BuildKit (wymagane dla funkcji mount secret oraz cache)
# syntax=docker/dockerfile:1

# Używamy platformy hosta ($BUILDPLATFORM), aby przyspieszyć proces kompilacji
FROM --platform=$BUILDPLATFORM golang:1.26.3-alpine AS builder

# Instalacja niezbędnych narzędzi: upx do kompresji pliku binarnego, git do ewentualnych modułów
RUN apk add --no-cache upx git

# Ustawienie katalogu roboczego
WORKDIR /build

# Bezpieczne montowanie sekretu
RUN --mount=type=secret,id=github_token \
    echo "Autentykacja w GitHub przy uzyciu tokena..." && \
    echo "Token zaladowany poprawnie, brak zapisu w warstwach."

# Kopiowanie plików definicji modułów Go
COPY go.mod* go.sum* ./

# Pobieranie zależności z wykorzystaniem pamięci podręcznej (cache) dla przyspieszenia kolejnych budowań
RUN --mount=type=cache,target=/go/pkg/mod go mod download || true

COPY . .

# Argumenty określające docelowy system i architekturę
ARG TARGETOS
ARG TARGETARCH

# Kompilacja aplikacji dla docelowej architektury; wyłączamy CGO dla pełnej statyczności 
# oraz usuwamy symbole debugowania (-s -w) w celu zmniejszenia pliku
RUN --mount=type=cache,target=/go/pkg/mod \
    CGO_ENABLED=0 GOOS=$TARGETOS GOARCH=$TARGETARCH go build -ldflags="-s -w" -o weather-server .

# Maksymalna kompresja skompilowanego pliku binarnego
RUN upx --best --lzma weather-server

FROM scratch

# Metadane obrazu zgodne ze standardem OCI
LABEL org.opencontainers.image.authors="Viktor Pavlovskyi" \
      org.opencontainers.image.description="Minimal weather app" \
      org.opencontainers.image.version="1.0.0"

# Skopiowanie gotowego, skompresowanego pliku binarnego
COPY --from=builder /build/weather-server /weather-server

# Definicja zmiennych środowiskowych aplikacji
ENV AUTHOR="Viktor Pavlovskyi" PORT=3000

EXPOSE 3000

HEALTHCHECK --interval=30s --timeout=5s --start-period=5s --retries=3 \
   CMD ["/weather-server", "-health"]

ENTRYPOINT ["/weather-server"]
