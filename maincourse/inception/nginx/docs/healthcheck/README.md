1. First, let's modify your Nginx Dockerfile to include a health check:

```dockerfile
FROM nginx:latest
COPY configuration/nginx.conf /etc/nginx/nginx.conf
COPY html /usr/share/nginx/html

# Install curl for the health check
RUN apt-get update && apt-get install -y curl && rm -rf /var/lib/apt/lists/*

# Add health check
HEALTHCHECK --interval=30s --timeout=3s \
  CMD curl -f http://localhost/ || exit 1

LABEL com.docker.compose.config='{"ContainerConfig":{}}'
```

This health check uses curl to make a request to the Nginx server every 30 seconds. If the request fails, the health check will fail.

2. Now, let's update your docker-compose.yml file to use this health check:

```yaml
services:
  nginx:
    build:
      context: ./nginx
      dockerfile: Dockerfile
    ports:
      - "80:80"
    volumes:
      - ./nginx/html:/usr/share/nginx/html
    healthcheck:
      test: ["CMD", "curl", "-f", "http://localhost/"]
      interval: 30s
      timeout: 3s
      retries: 3
      start_period: 40s
```

This configuration tells Docker Compose to use the health check defined in the Dockerfile. It will:
- Run the test command every 30 seconds
- Wait up to 3 seconds for a response
- Retry up to 3 times before considering the container unhealthy
- Wait for 40 seconds after the container starts before beginning health checks

3. To test this setup:

   a. Build and start your containers:
   ```
   docker-compose up --build -d
   ```

   b. Check the status of your containers:
   ```
   docker-compose ps
   ```

   You should see the health status of your Nginx container.

   c. View the health check logs:
   ```
   docker inspect --format='{{json .State.Health}}' nginx_container_name | jq
   ```
   Replace `nginx_container_name` with the actual name of your Nginx container.

4. To simulate an unhealthy state, you could temporarily modify your Nginx configuration to return a 500 error for all requests:

   In your `nginx.conf`:
   ```nginx
   server {
       listen 80;
       server_name localhost;
       return 500;
   }
   ```

   Then rebuild and restart your containers. You should see the health checks start to fail.

5. You can also use health checks in your Compose file to control startup order. For example, if you had a backend service that Nginx depends on:

```yaml
services:
  nginx:
    # ... (as before)
    depends_on:
      backend:
        condition: service_healthy

  backend:
    image: your-backend-image
    healthcheck:
      test: ["CMD", "curl", "-f", "http://localhost:8080/health"]
      interval: 30s
      timeout: 3s
      retries: 3
      start_period: 40s
```

This setup ensures that Nginx only starts after the backend service is healthy.
