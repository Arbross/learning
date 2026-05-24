## Informacja o aplikacji znajduje się w katalogu repozytorium 'Zadanie 1'
## 6. GitHub Actions Pipeline

W katalogu `.github/workflows/docker-build.yml` znajduje się zautomatyzowany łańcuch CI/CD.

### 6.1. Architektura workflow

| Krok | Opis |
|------|------|
| Checkout | Pobranie kodu źródłowego |
| QEMU + Buildx | Przygotowanie emulatora oraz buildera multi-platform |
| Logowanie do rejestrów | DockerHub (cache) oraz GHCR (`ghcr.io`) |
| Build (linux/amd64) | Lokalna budowa obrazu pod skanowanie |
| Trivy CVE Scan | Analiza podatności z blokadą przy `CRITICAL` / `HIGH` |
| Build multi-platform | Budowa i push obrazów `linux/amd64` + `linux/arm64` do GHCR |

### 6.2. Wymagane secrety

| Nazwa | Opis |
|-------|------|
| `DOCKERHUB_USERNAME` | Login do Docker Hub |
| `DOCKERHUB_TOKEN` | Access Token (nie hasło!) z Docker Hub |

Token do GHCR generowany jest automatycznie przez GitHub (`GITHUB_TOKEN`), dlatego nie wymaga dodatkowej konfiguracji.

### 6.3. Sposób tagowania obrazów
#### Obraz aplikacji

- `latest` - zawsze wskazuje na ostatnią pomyślną wersję z gałęzi `main`. Jest wygodny w użyciu przy szybkich testach i lokalnym uruchamianiu, jednak nie jest zalecany w produkcji ze względu na mutable nature.
- `sha-<short>` — tag immutable oparty na skróconym hashu commitu git. Gwarantuje unikalność oraz umożliwia jednoznaczną identyfikację wersji kodu zawartej w obrazie.
