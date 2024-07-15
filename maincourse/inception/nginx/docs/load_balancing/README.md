# Introduction
Load balancing with Nginx is a great way to distribute traffic across multiple servers, improving your application's performance, scalability, and reliability.

# How to?
1. We'll need multiple backend services to balance the load between. Create a new directory for a simple backend service:

```
mkdir -p src/backend
touch src/backend/Dockerfile
touch src/backend/app.js
```

2. Create a simple Node.js application in `src/backend/app.js`:

```javascript
const http = require('http');
const os = require('os');

const server = http.createServer((req, res) => {
  res.writeHead(200, { 'Content-Type': 'text/plain' });
  res.end(`Hello from ${os.hostname()}\n`);
});

server.listen(3000, () => {
  console.log('Server running on port 3000');
});
```

3. Create a Dockerfile for the backend in `src/backend/Dockerfile`:

```dockerfile
FROM node:14-alpine
WORKDIR /app
COPY app.js .
CMD ["node", "app.js"]
```

4. Modify your `docker-compose.yml` to include multiple backend instances and update the Nginx service:

```yaml
services:
  nginx:
    build:
      context: ./nginx
      dockerfile: Dockerfile
    ports:
      - "80:80"
    depends_on:
      - backend1
      - backend2
      - backend3

  backend1:
    build:
      context: ./backend
      dockerfile: Dockerfile

  backend2:
    build:
      context: ./backend
      dockerfile: Dockerfile

  backend3:
    build:
      context: ./backend
      dockerfile: Dockerfile
```

5. Update your Nginx configuration (`src/nginx/configuration/nginx.conf`) to implement load balancing:

```nginx
events {
    worker_connections 1024;
}

http {
    upstream backend {
        server backend1:3000;
        server backend2:3000;
        server backend3:3000;
    }

    server {
        listen 80;

        location / {
            proxy_pass http://backend;
            proxy_set_header Host $host;
            proxy_set_header X-Real-IP $remote_addr;
        }
    }
}
```

This configuration defines an upstream group called `backend` that includes our three backend services. The `location` block then uses `proxy_pass` to forward requests to this upstream group.

6. Build and run your Docker Compose setup:

```
docker-compose up --build
```

7. Test your load balancing setup by making multiple requests to `http://localhost`. You should see responses from different backend instances.

To further explore and enhance this setup, you could:

- Implement different load balancing algorithms (e.g., least_conn, ip_hash)
- Add health checks to your backend services
- Implement SSL termination at the Nginx level
- Set up sticky sessions for stateful applications
- Explore rate limiting and request throttling with Nginx
