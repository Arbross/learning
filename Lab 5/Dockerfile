# ETAP 1
FROM golang:alpine AS builder
WORKDIR /app
COPY main.go .
RUN go build -o app_server main.go

# ETAP 2
FROM nginx:alpine

# Argumenty i zmienne
ARG VERSION=1.0.0
ENV VERSION=${VERSION}

# Instalacja curl dla HEALTHCHECK
RUN apk add --no-cache curl

# Kopiujemy skompilowany serwer Go
COPY --from=builder /app/app_server /usr/local/bin/app_server

# Kopiujemy konfigurację proxy
COPY nginx.conf /etc/nginx/conf.d/default.conf

CMD app_server & nginx -g 'daemon off;'

HEALTHCHECK --interval=10s --timeout=3s CMD curl -f http://localhost/ || exit 1

EXPOSE 80
