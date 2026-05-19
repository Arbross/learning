FROM golang:1.22-alpine AS builder

# Instalacja narzędzia UPX do kompresji pliku wykonywalnego
RUN apk add --no-cache upx

# Ustawienie katalogu roboczego wewnątrz kontenera na czas budowania
WORKDIR /build

# Skopiowanie wszystkich plików z lokalnego katalogu do kontenera
COPY . .

# Budowanie statycznie pliku binarnego zoptymalizowanego pod Linuksa (bez symboli debugowania)
RUN CGO_ENABLED=0 GOOS=linux go build -ldflags="-s -w" -o weather-server .

# Kompresja pliku binarnego za pomocą UPX z maksymalnymi ustawieniami wydajności
RUN upx --best --lzma weather-server

FROM scratch

# Metadane i etykiety informacyjne o obrazie kontenera
LABEL org.opencontainers.image.authors="Viktor Pavlovskyi" \
      org.opencontainers.image.description="Minimal weather app" \
      org.opencontainers.image.version="1.0.0" \
      org.opencontainers.image.licenses="MIT"

# Skopiowanie skompresowanego pliku binarnego z etapu budowania do nowego obrazu
COPY --from=builder /build/weather-server /weather-server

# Ustawienie zmiennych środowiskowych
ENV AUTHOR="Viktor Pavlovskyi" PORT=3000

EXPOSE 3000

HEALTHCHECK --interval=30s --timeout=5s --start-period=5s --retries=3 \
  CMD ["/weather-server", "-health"]

# Główna komenda, która uruchomi aplikację startową przy starcie kontenera
ENTRYPOINT ["/weather-server"]
