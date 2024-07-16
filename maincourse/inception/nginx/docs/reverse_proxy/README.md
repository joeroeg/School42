# What is a Reverse Proxy?
In a nutshell, a reverse proxy is a server that sits in front of your backend web servers (like your application servers or APIs). It intercepts requests from clients (web browsers, mobile apps, etc.) and forwards them to the appropriate backend server. The response from the backend is then passed back through the reverse proxy to the client.

# Why Use a Reverse Proxy?
- Load Balancing: Distributes incoming traffic across multiple backend servers to prevent any single server from becoming overwhelmed.
- Security: Acts as a buffer between the internet and your backend servers, protecting them from direct exposure and potential attacks.
- Caching: Stores copies of frequently accessed content to speed up delivery to clients.
- SSL Termination: Handles the encryption and decryption of HTTPS traffic, offloading this task from your backend servers.

# How to?
1. First, let's create two simple backend services. We'll use Python with Flask for variety. Create two new directories:

```bash
mkdir -p src/service1 src/service2
```

2. Create a Flask app for service1 in `src/service1/app.py`:

```python
from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello():
    return "Hello from Service 1!"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
```

3. Create a similar app for service2 in `src/service2/app.py`:

```python
from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello():
    return "Hello from Service 2!"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
```

4. Create Dockerfiles for both services. In `src/service1/Dockerfile` and `src/service2/Dockerfile`:

```dockerfile
FROM python:3.9-slim
WORKDIR /app
COPY app.py .
RUN pip install flask
CMD ["python", "app.py"]
```

5. Update your `docker-compose.yml` to include these new services:

```yaml
version: '3'
services:
  nginx:
    build:
      context: ./nginx
      dockerfile: Dockerfile
    ports:
      - "80:80"
    depends_on:
      - service1
      - service2

  service1:
    build:
      context: ./service1
      dockerfile: Dockerfile

  service2:
    build:
      context: ./service2
      dockerfile: Dockerfile
```

6. Now, let's update the Nginx configuration to act as a reverse proxy. Modify `src/nginx/configuration/nginx.conf`:

```nginx
events {
    worker_connections 1024;
}

http {
    server {
        listen 80;

        location /service1 {
            proxy_pass http://service1:5000/;
            proxy_set_header Host $host;
            proxy_set_header X-Real-IP $remote_addr;
        }

        location /service2 {
            proxy_pass http://service2:5000/;
            proxy_set_header Host $host;
            proxy_set_header X-Real-IP $remote_addr;
        }

        location / {
            return 200 'Welcome to the reverse proxy!';
        }
    }
}
```

This configuration does the following:
- Requests to `/service1` are proxied to the service1 container.
- Requests to `/service2` are proxied to the service2 container.
- Any other request returns a welcome message.

7. Build and run your Docker Compose setup:

```bash
docker-compose up --build
```

8. Test your reverse proxy setup:
   - Visit `http://localhost/service1` - You should see "Hello from Service 1!"
   - Visit `http://localhost/service2` - You should see "Hello from Service 2!"
   - Visit `http://localhost/` - You should see "Welcome to the reverse proxy!"

To further explore and enhance this reverse proxy setup, you could:

- Implement URL rewriting
- Set up SSL termination
- Configure caching for proxied content
- Implement access control or authentication at the Nginx level
- Set up monitoring and logging for your proxy

# How does it work?

1. Direction of traffic:
   A reverse proxy sits in front of backend servers and forwards client requests to those servers. In our setup, Nginx is sitting in front of our Flask services (service1 and service2) and forwarding requests to them.

2. Client perspective:
   Clients send requests to the reverse proxy (Nginx) as if it was the final destination. They don't know about or directly interact with the backend servers. In our case, clients are sending requests to `http://localhost/service1` or `http://localhost/service2`, not directly to the Flask apps.

3. Request handling:
   The reverse proxy receives the initial request from the client, then sends a request to the backend server, retrieves the response, and forwards it back to the client. This is exactly what our Nginx configuration is doing with the `proxy_pass` directives.

4. URL mapping:
   Our Nginx configuration maps different URL paths to different backend services:
   ```nginx
   location /service1 {
       proxy_pass http://service1:5000/;
   }

   location /service2 {
       proxy_pass http://service2:5000/;
   }
   ```
   This is a key feature of reverse proxies - they can route requests based on the URL path.

5. Header modification:
   Reverse proxies often modify request headers before forwarding them to backend servers. In our configuration, we're setting the `Host` and `X-Real-IP` headers:
   ```nginx
   proxy_set_header Host $host;
   proxy_set_header X-Real-IP $remote_addr;
   ```
   This allows the backend servers to know the original client's IP and the hostname used in the request.

6. Single point of entry:
   All client requests go through Nginx, which then decides where to route them. This creates a single entry point for the application, which is a characteristic of reverse proxies.

7. Abstraction of backend infrastructure:
   Clients don't need to know anything about the backend services or how they're implemented. They just interact with Nginx. This abstraction is a key feature of reverse proxies.

Why use a reverse proxy?

1. Load balancing: While not implemented in this basic example, reverse proxies can distribute traffic across multiple backend servers.
2. Increased security: The reverse proxy can hide information about backend servers, providing an additional layer of security.
3. SSL termination: The reverse proxy can handle incoming HTTPS connections, decrypting requests and encrypting responses, reducing load on backend servers.
4. Caching: Reverse proxies can cache content, reducing load on backend servers for frequently requested content.
5. Compression: Responses can be compressed at the reverse proxy level before being sent to clients.
6. Centralized logging and monitoring: Since all requests go through the reverse proxy, it's an ideal place to implement logging and monitoring.

In essence, this implementation is a reverse proxy because it acts as an intermediary between clients and our backend services, forwarding requests and responses while providing additional functionality and control over the communication flow.

# What is the difference when load balancing implemented with proxy server and without it?

## Load Balancing Without a Proxy Server:

1. Direct Server Return (DSR):
   - Requests are distributed by a dedicated load balancer device or software.
   - The load balancer only handles incoming traffic.
   - Responses go directly from the backend servers to the clients.

2. Network Address Translation (NAT):
   - The load balancer modifies the destination IP of incoming packets.
   - Backend servers are typically on a private network.
   - Responses route back through the load balancer.

Characteristics:
- Often implemented at the network layer (Layer 4 of the OSI model).
- Can be very fast and efficient for simple distribution of TCP/UDP traffic.
- Limited application-level intelligence.
- Typically requires specialized hardware or software.

## Load Balancing With a Proxy Server:

1. Application-level load balancing:
   - The proxy server acts as both the load balancer and the reverse proxy.
   - All traffic (requests and responses) passes through the proxy.

Characteristics:
- Operates at the application layer (Layer 7 of the OSI model).
- Can make routing decisions based on application-specific data (e.g., HTTP headers, URL paths).
- Provides additional features like SSL termination, caching, compression.
- Can modify requests and responses.

Key Differences:

1. Traffic Flow:
   - Without proxy: Client → Load Balancer → Backend Server → Client
   - With proxy: Client → Proxy (Load Balancer) → Backend Server → Proxy → Client

2. Flexibility:
   - Proxy-based load balancing offers more flexibility in routing decisions and request handling.

3. Feature Set:
   - Proxy servers typically offer a richer set of features beyond just load balancing.

4. Performance:
   - Non-proxy load balancers can potentially offer better performance for simple traffic distribution.
   - Proxy-based solutions may introduce slight latency but offer more functionality.

5. Visibility:
   - Proxy-based solutions have full visibility into the request/response cycle.
   - Non-proxy solutions may have limited visibility, especially with DSR.

6. Backend Server Configuration:
   - Non-proxy solutions often require special configuration on backend servers.
   - Proxy-based solutions usually require minimal changes to backend servers.

7. SSL Handling:
   - Proxy-based solutions can easily handle SSL termination.
   - Non-proxy solutions may require SSL to be handled by backend servers or additional components.

8. Application Intelligence:
   - Proxy-based solutions can make decisions based on application-specific data.
   - Non-proxy solutions typically work with network-level information only.

In the context of our Nginx example, implementing load balancing with a proxy server allows us to:
- Easily distribute traffic based on URL paths or other HTTP-specific criteria.
- Implement additional features like caching, compression, or authentication in the same component.
- Modify requests and responses as needed.
- Handle SSL termination efficiently.

This makes the proxy-based approach very powerful and flexible, especially for web applications, although it may introduce a small performance overhead compared to specialized layer 4 load balancers.
