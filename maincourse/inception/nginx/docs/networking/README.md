# What is docker networking?
Docker networking is a crucial aspect of Docker that enables communication between containers and between containers and the outside world.

1. Network Drivers:
   Docker uses different network drivers to provide networking capabilities. The main types are:

   - Bridge: The default network driver. It creates a private network inside the host for containers to communicate.
   - Host: Removes network isolation between the container and the Docker host, using the host's networking directly.
   - Overlay: Enables communication between containers across multiple Docker daemon hosts.
   - Macvlan: Allows you to assign a MAC address to a container, making it appear as a physical device on your network.
   - None: Disables all networking for a container.

2. Default Bridge Network:
   When you install Docker, it automatically creates a default bridge network named "bridge". All new containers are attached to this network by default unless specified otherwise.

3. Container Network Interface (CNI):
   Docker uses CNI to set up and manage container networking. It handles tasks like IP address assignment, routing, and network isolation.

4. DNS Resolution:
   Docker provides built-in DNS resolution for containers. Containers can refer to each other by their names if they're on the same network.

5. Port Mapping:
   Docker allows you to map ports from the container to ports on the host system, enabling external access to services running inside containers.

6. Network Namespaces:
   Docker uses Linux network namespaces to provide network isolation between containers.

7. Custom Networks:
   You can create your own networks using `docker network create`. This allows for better isolation and control over which containers can communicate with each other.

8. Network Plugins:
   Docker supports third-party network plugins that can provide additional networking capabilities.

How it works in practice:

1. When you start a container, Docker connects one end of a virtual ethernet pair (veth) to the container and the other end to a Docker bridge on the host.

2. Each container gets its own IP address, typically in a private subnet (like 172.17.0.0/16 for the default bridge network).

3. Containers on the same network can communicate directly using these IP addresses or container names.

4. For communication with the outside world, Docker sets up NAT (Network Address Translation) rules on the host to route traffic to the appropriate containers.

5. When you create custom networks, Docker sets up additional bridges and routing rules to manage traffic between different networks.

Understanding Docker networking helps in designing robust, scalable, and secure containerized applications.
It's particularly important when working with multi-container applications or microservices architectures.


# How to
1. List current networks:
   First, let's see what networks already exist:

   ```
   docker network ls
   ```

2. Create a custom bridge network:
   ```
   docker network create my_custom_network
   ```

3. Inspect the network:
   ```
   docker network inspect my_custom_network
   ```

4. Modify your docker-compose.yml to use the custom network:
   ```yaml
   version: '3'
   services:
     nginx:
       build:
         context: ./nginx
         dockerfile: Dockerfile
       ports:
         - "80:80"
       volumes:
         - ./nginx/html:/usr/share/nginx/html
       networks:
         - my_custom_network

   networks:
     my_custom_network:
       external: true
   ```

5. Create another service to demonstrate inter-container communication:
   Add a simple web application container, like a Python Flask app. Create a new directory `flask_app` next to your `nginx` directory with the following files:

   `app.py`:
   ```python
   from flask import Flask
   app = Flask(__name__)

   @app.route('/')
   def hello():
       return "Hello from Flask!"

   if __name__ == '__main__':
       app.run(host='0.0.0.0', port=5000)
   ```

   `Dockerfile`:
   ```dockerfile
   FROM python:3.9-slim
   WORKDIR /app
   COPY requirements.txt .
   RUN pip install -r requirements.txt
   COPY . .
   CMD ["python", "app.py"]
   ```

   `requirements.txt`:
   ```
   Flask==2.0.1
   ```

6. Update your docker-compose.yml to include the Flask app:
   ```yaml
   version: '3'
   services:
     nginx:
       build:
         context: ./nginx
         dockerfile: Dockerfile
       ports:
         - "80:80"
       volumes:
         - ./nginx/html:/usr/share/nginx/html
       networks:
         - my_custom_network

     flask_app:
       build:
         context: ./flask_app
         dockerfile: Dockerfile
       networks:
         - my_custom_network

   networks:
     my_custom_network:
       external: true
   ```

7. Update your Nginx configuration to proxy requests to the Flask app:
   In `nginx.conf`:
   ```nginx
   http {
     server {
       listen 80;
       location / {
         proxy_pass http://flask_app:5000;
       }
     }
   }
   ```

8. Build and run your containers:
   ```
   docker-compose up --build
   ```

9. Test the connection:
   Visit `http://localhost` in your browser. You should see "Hello from Flask!"

10. Experiment with network isolation:
    Create another network and assign only one container to it to see how network isolation works.

To further explore and enhance your Docker networking setup, you could try the following:

1. Implement service discovery: Use Docker's built-in DNS to allow containers to communicate using service names. Modify your Nginx configuration to use the service name instead of IP address.
2. Create multiple networks: Set up different networks for front-end and back-end services to improve security isolation.
3. Explore network drivers: Experiment with different network drivers like bridge, host, overlay, and macvlan.
4. Implement a load balancer: Add multiple instances of your Flask app and use Nginx as a load balancer.
5. Set up cross-host networking: If you have multiple Docker hosts, explore overlay networks for communication across hosts.
6. Use network aliases: Assign aliases to your services and use them for communication.
7. Implement network policies: If using Docker Swarm or Kubernetes, explore network policies to control traffic flow between services.
8. Monitor network traffic: Use tools like tcpdump or Wireshark to analyze network traffic between containers.
9. Explore Docker Compose networking features: Use features like networks.ipam to configure IP address management.
10. Implement service mesh: Explore service mesh solutions like Istio or Linkerd for advanced networking features.

# What we did?
1. Custom Network Creation:
   We created a custom network instead of using the default bridge network. This gives us more control over container communication.

2. Connecting Nginx and Flask:
   Yes, we connected Nginx and Flask to the same custom network. This allows them to communicate using their service names as hostnames.

The key benefits and learning points from this exercise are:

1. Network Isolation:
   Custom networks provide better isolation. Containers on this network can communicate with each other, but not with containers on other networks unless explicitly connected.

2. Service Discovery:
   Docker provides built-in DNS for custom networks. This means our Nginx container can reach the Flask container using the hostname "flask_app" without needing to know its IP address.

3. Security:
   By using custom networks, we can control which containers can communicate with each other, enhancing security.

4. Scalability:
   This setup makes it easier to scale services. If you add more Flask containers, Docker's built-in load balancing will distribute requests among them automatically.

5. Network Separation:
   You can create multiple custom networks to segment your application tiers (e.g., frontend, backend, database networks).

To further explore and understand these concepts, you could try:

1. Creating multiple custom networks and seeing how containers on different networks can't communicate by default.

2. Using the `docker network connect` and `docker network disconnect` commands to dynamically add or remove containers from networks.

3. Experimenting with the `--link` flag (though it's considered legacy) to understand why custom networks are a better solution.

4. Using `docker network inspect` to see detailed information about your custom network.


