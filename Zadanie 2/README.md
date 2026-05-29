## Zadanie 2 - GitHub Actions Pipeline

Cały kod aplikacji znajduje się w katalogu **Zadanie 1** (wraz z Dockerfile), a pipeline znajduje się w głównym katalogu repozytorium. Tutaj opisany jest pipeline CI/CD, który automatycznie buduje obraz, skanuje go pod kątem podatności i wysyła do GHCR.

### Co robi workflow?

Plik `.github/workflows/docker-build.yml` uruchamia się przy każdym pushu na gałąź `docker`. Składa się z następujących kroków:

1. **Checkout** - pobiera kod z repozytorium.
2. **QEMU + Buildx** - ustawia emulator i builder wieloplatformowy, żeby można było zbudować obraz zarówno na `amd64`, jak i `arm64`.
3. **Logowanie do rejestrów** - loguje się do DockerHub (potrzebny do cache) oraz do GHCR (automatycznie za pomocą `GITHUB_TOKEN`).
4. **Wyciągnięcie metadanych** - przygotowuje tagi dla obrazu.
5. **Build pod skanowanie** - buduje obraz tylko na `linux/amd64` i zapisuje lokalnie, żeby Trivy mógł go sprawdzić.
6. **Trivy CVE Scan** - skanuje obraz. Jeśli znajdzie podatności `CRITICAL` lub `HIGH`, pipeline kończy się błędem i obraz nie trafi do rejestru.
7. **Build i push** - jeśli skanowanie przeszło OK, buduje obraz na obie platformy i wysyła go do `ghcr.io`.

### Wymagane secrety

W ustawieniach repozytorium (Settings -> Secrets and variables -> Actions) trzeba dodać:

| Nazwa | Co to |
|-------|-------|
| `DOCKERHUB_USERNAME` | Login do DockerHub |
| `DOCKERHUB_TOKEN` | Access Token z DockerHub |

Token do GHCR generuje się sam przez GitHub (`GITHUB_TOKEN`).

### Sposób tagowania

#### Obraz aplikacji

- **`latest`** - zawsze wskazuje na najnowszą działającą wersję. Wygodny, gdy chcemy szybko pobrać obraz bez zastanawiania się, która wersja jest najświeższa.
- **`sha-<short>`** - tag stworzony na podstawie skróconego hasha commitu (sha-a1b2c3d). Jest niemodyfikowalny, więc zawsze wiadomo, jaki dokładnie kod znajduje się w obrazie. Przydatny do wersjonowania i cofania się do starszych wersji.

#### Cache

Cache jest przechowywany jako osobne repozytorium na DockerHub: `weather-app-cache:buildcache`. Dzięki temu kolejne buildy nie muszą budować wszystkiego od zera - wystarczy pobrać gotowe warstwy. Używamy trybu `max`, co oznacza, że zapisywane są wszystkie warstwy pośrednie, a nie tylko z finalnego obrazu.

### Dlaczego Trivy, a nie Docker Scout?

Wybrałem **Trivy**, bo działa od razu, wystarczy dodać akcję `aquasecurity/trivy-action` i gotowe. Nie wymaga subskrypcji Docker Pro ani konfiguracji organizacji w DockerHub. Trivy potrafi zwrócić kod błędu, gdy znajdzie krytyczne lub wysokie zagrożenia, co automatycznie blokuje push do rejestru.

[Adres URL na GHCR (GitHub)](https://github.com/Arbross/learning/pkgs/container/learning)
[Adres URL na cache (Docker Hub)](https://hub.docker.com/r/arbross/weather-app-cache)
