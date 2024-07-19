# Variables
COMPOSE_FILE := srcs/docker-compose.yml
DOCKER_COMPOSE := docker-compose -f $(COMPOSE_FILE) #--verbose
MARIA_VOL = /home/device/data/mariadb
WORDPRESS_VOL = /home/device/data/wordpress

# Default target
.DEFAULT_GOAL := help

.PHONY: help
help:  ## Show this help message
	@echo "Usage: make [target]"
	@awk 'BEGIN {FS = ":.*##"; printf "\033[36m%-20s\033[0m %s\n", "Targets:", " Description:"} /^[a-zA-Z_-]+:.*?##/ { printf "\033[36m%-20s\033[0m %s\n", $$1, $$2 }' $(MAKEFILE_LIST)

.PHONY: build
build:  ## Build the Docker image
	$(DOCKER_COMPOSE) build

.PHONY: up
up:  ## Build and start the containers in detached mode
	@mkdir -p  $(MARIA_VOL) $(WORDPRESS_VOL)
	$(DOCKER_COMPOSE) up --build

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

stats:
	@echo "Containers:"
	@docker ps -a
	@echo "\nNetworks:"
	@docker network ls
	@echo "\nImages:"
	@docker images
	@echo "\nVolumes:"
	@docker volume ls


.PHONY: clean
clean: ## Remove all stopped containers, networks, and volumes
    # Stop and remove containers defined in docker-compose.yml along with volumes
	$(DOCKER_COMPOSE) down -v

    # Clean up unused Docker resources
	docker system prune -f --volumes
	docker network prune -f
	docker volume prune -f

	@images=$$(docker image ls -q) && \
	if [ -n "$$images" ]; then \
		docker image rm -f $$images; \
	fi

	@containers=$$(docker container ls -a -q) && \
	if [ -n "$$containers" ]; then \
		docker container rm -f $$containers; \
	fi

	@sudo rm -rf $(MARIA_VOL) $(WORDPRESS_VOL)
	@sudo rm -rf /home/device/data/


.PHONY: rebuild
rebuild:  ## Rebuild the Docker image without cache
	@mkdir -p  $(MARIA_VOL) $(WORDPRESS_VOL)
	$(DOCKER_COMPOSE) build --no-cache
	$(DOCKER_COMPOSE) up --build --force-recreate --no-deps --remove-orphans

.PHONY: encrypt
encrypt: ## Encrypt the .env file
	@echo "Encrypting .env file..."
	@gpg --symmetric --cipher-algo AES256 srcs/.env || (echo "Encryption failed"; exit 1)
	@echo "Encryption successful"

.PHONY: decrypt
decrypt: ## Decrypt the .env file
	@echo "Decrypting .env file..."
	@stty -echo; printf "Enter passphrase: "; \
	read PASSPHRASE; \
	stty echo; \
	echo; \
	echo $$PASSPHRASE | gpg --pinentry-mode loopback --passphrase-fd 0 --batch --yes --decrypt srcs/.env.gpg > srcs/.env || (echo "Decryption failed"; exit 1)
	@echo "Decryption successful"

.PHONY: clean-env
clean-env: ## Remove the decrypted .env file
	@echo "Removing decrypted .env file..."
	@rm -f srcs/.env
	@echo "Cleanup complete"

.PHONY: mysql
mysql: ## Run mysql script
	./scripts/mysql.sh

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
