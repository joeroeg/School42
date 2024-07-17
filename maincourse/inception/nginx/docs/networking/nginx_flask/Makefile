# Variables
COMPOSE_FILE := src/docker-compose.yml
DOCKER_COMPOSE := docker-compose -f $(COMPOSE_FILE) #--verbose

# Default target
.DEFAULT_GOAL := help

.PHONY: help
help:  ## Show this help message
	@echo "Usage: make [target]"
	@echo
	@echo "Targets:"
	@awk 'BEGIN {FS = ":.*##"; printf "\033[36m%-20s\033[0m %s\n", "Target", "Description"} /^[a-zA-Z_-]+:.*?##/ { printf "\033[36m%-20s\033[0m %s\n", $$1, $$2 }' $(MAKEFILE_LIST)

.PHONY: build
build:  ## Build the Docker image
	$(DOCKER_COMPOSE) build

.PHONY: up
up:  ## Build and start the containers in detached mode
	$(DOCKER_COMPOSE) up -d --build

.PHONY: down
down:  ## Stop and remove the containers
	$(DOCKER_COMPOSE) down

.PHONY: restart
restart:  ## Restart the Docker containers
	$(DOCKER_COMPOSE) down
	$(DOCKER_COMPOSE) up -d

.PHONY: logs
logs:  ## Show logs of the Docker containers
	$(DOCKER_COMPOSE) logs -f

.PHONY: ps
ps:  ## List containers
	$(DOCKER_COMPOSE) ps

.PHONY: clean
clean:  ## Remove all stopped containers, networks, and volumes
	$(DOCKER_COMPOSE) down -v
	docker system prune -f --volumes
	docker image prune -a -f

.PHONY: rebuild
rebuild:  ## Rebuild the Docker image without cache
	$(DOCKER_COMPOSE) build --no-cache
	$(DOCKER_COMPOSE) up -d --build --force-recreate --no-deps --remove-orphans

.PHONY: check-versions
check-versions:  ## Check versions of Docker-related packages
	@echo "Docker version:"
	@docker --version
	@echo "\nDocker Compose version:"
	@docker-compose --version
	@echo "\nContainerd version:"
	@containerd --version
	@echo "\nRunC version:"
	@runc --version
	@echo "\nDocker Buildx version:"
	@docker buildx version
	@echo "\nDocker Compose Plugin version:"
	@docker compose version

.PHONY: install-docker
install-docker:  ## Install or update Docker and related packages
	@echo "Removing existing Docker installation..."
	sudo apt remove docker docker-engine docker.io containerd runc || true
	@echo "Setting up Docker repository..."
	sudo apt-get update
	sudo apt-get install -y ca-certificates curl gnupg
	sudo install -m 0755 -d /etc/apt/keyrings
	curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
	sudo chmod a+r /etc/apt/keyrings/docker.gpg
	echo "deb [arch=$$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu $$(. /etc/os-release && echo "$$VERSION_CODENAME") stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
	@echo "Updating package index..."
	sudo apt-get update
	@echo "Installing Docker Engine and related packages..."
	sudo apt-get install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
	@echo "Removing old docker-compose..."
	sudo apt remove docker-compose
	@echo "Installing latest Docker Compose..."
	sudo curl -L "https://github.com/docker/compose/releases/latest/download/docker-compose-$$(uname -s)-$$(uname -m)" -o /usr/local/bin/docker-compose
	sudo chmod +x /usr/local/bin/docker-compose
	@echo "Installation complete. Please reboot your system if you encounter any issues."
