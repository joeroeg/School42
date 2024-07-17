FROM nginx:latest
COPY configuration/nginx.conf /etc/nginx/nginx.conf
COPY html /usr/share/nginx/html

# Install curl for the health check
RUN apt-get update && apt-get install -y curl && rm -rf /var/lib/apt/lists/*

# Add health check
HEALTHCHECK --interval=30s --timeout=3s \
  CMD curl -f http://localhost/ || exit 1

LABEL com.docker.compose.config='{"ContainerConfig":{}}'
