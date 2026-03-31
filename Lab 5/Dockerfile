# Etap 1
FROM golang:alpine AS builder

WORKDIR /app
COPY main.go .

# Definicja zmiennej określonej w poleceniu docker build
ARG VERSION=1.0.0
ENV VERSION=${VERSION}

RUN go run main.go

# Etap 2
FROM nginx:alpine

# Dodanie curl dla HEALTHCHECK
RUN apk add --no-cache curl

# Aplikacja z etapu 1 jest kopiowana na serwer i ustawiana jako strona startowa
COPY --from=builder /app/index.html /usr/share/nginx/html/index.html

# Sprawdzanie poprawności działania
HEALTHCHECK --interval=10s --timeout=3s CMD curl -f http://localhost/ || exit 1

EXPOSE 80
