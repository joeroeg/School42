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

# How to analyze docker inspect file?

Analyzing the output from `docker inspect` involves breaking down the JSON data to understand the container's configuration and state. Here's a detailed analysis:

### 1. **Basic Information**
- **ID**: The unique identifier of the container.
- **Created**: The timestamp when the container was created.
- **Path**: The command used to run the container (in this case, `python`).
- **Args**: Arguments passed to the command (`app.py`).

### 2. **State**
- **Status**: Current status of the container (`running`).
- **Running**: Whether the container is currently running (`true`).
- **Paused**: Whether the container is paused (`false`).
- **Restarting**: Whether the container is restarting (`false`).
- **OOMKilled**: Whether the container was killed due to an out-of-memory issue (`false`).
- **Dead**: Whether the container is dead (`false`).
- **Pid**: The process ID of the container's main process (9069).
- **ExitCode**: The exit code of the container's main process (0 indicates successful execution).
- **Error**: Any error message (empty in this case).
- **StartedAt**: Timestamp when the container started.
- **FinishedAt**: Timestamp when the container finished (not applicable here as it's still running).

### 3. **Image**
- **Image**: The hash of the image used to create the container (`sha256:b3f2cf96b61c...`).

### 4. **Paths**
- **ResolvConfPath**: Path to the container's resolv.conf file.
- **HostnamePath**: Path to the container's hostname file.
- **HostsPath**: Path to the container's hosts file.
- **LogPath**: Path to the container's log file.

### 5. **Name**
- **Name**: Name of the container (`/src-flask_app-1`).

### 6. **Restart Policy**
- **RestartPolicy**: Configuration for how the container should be restarted (`no` restart policy).

### 7. **Host Configuration**
- **NetworkMode**: The network mode the container is using (`src_default`).
- **PortBindings**: Port bindings for the container (empty here).
- **VolumesFrom**: Volumes mounted from other containers (null here).
- **ConsoleSize**: Size of the console (0x0).

### 8. **Security**
- **AppArmorProfile**: The AppArmor profile applied (`docker-default`).
- **SecurityOpt**: Security options (null).

### 9. **Resource Limits**
- **CpuShares**, **Memory**, **NanoCpus**: CPU and memory limits (all set to defaults here).
- **BlkioWeight**, **BlkioDeviceReadBps**, **BlkioDeviceWriteBps**: Block IO settings (defaults).

### 10. **Graph Driver**
- **GraphDriver**: Information about the storage driver used (`overlay2`).

### 11. **Mounts**
- **Mounts**: Details of mounted volumes (empty in this case).

### 12. **Configuration**
- **Hostname**: The hostname inside the container (`2592bd2d4412`).
- **Env**: Environment variables set inside the container.
  - Examples: `PATH`, `LANG`, `PYTHON_VERSION`, etc.
- **Cmd**: The command and arguments to run inside the container (`python app.py`).
- **Image**: The image used to create the container (`src-flask_app`).
- **WorkingDir**: The working directory inside the container (`/app`).
- **Labels**: Metadata labels, especially those related to Docker Compose.

### 13. **Network Settings**
- **Networks**: Details about the networks the container is connected to.
  - **NetworkID**: The ID of the network (`8d9a5e021c06...`).
  - **Gateway**: The gateway IP (`172.18.0.1`).
  - **IPAddress**: The IP address of the container (`172.18.0.2`).
  - **Aliases**: Network aliases (`src-flask_app-1`, `flask_app`).

### Steps to Debug Issues

1. **Check the Status and Logs**:
   - The container is running without errors (`Status: "running"` and `Error: ""`).
   - Check the logs for any runtime issues: `docker logs src-flask_app-1`.

2. **Verify Network Configuration**:
   - Ensure the container has the correct IP and is connected to the expected network (`IPAddress: "172.18.0.2"`, `NetworkMode: "src_default"`).

3. **Review Environment Variables**:
   - Ensure necessary environment variables are correctly set (`PYTHON_VERSION`, `PATH`, etc.).

4. **Check Resource Limits**:
   - Verify if resource limits are correctly set and sufficient (`CpuShares`, `Memory`).

5. **Examine Volumes and Mounts**:
   - Check if any volumes are correctly mounted (if applicable).

6. **Inspect File Paths**:
   - Verify paths for resolv.conf, hostname, hosts, and log files to ensure they are correctly set.

### Example Debugging Commands

- **Real-time Logs**:
  ```bash
  docker logs -f src-flask_app-1
  ```

- **Check Network Connections**:
  ```bash
  docker network inspect src_default
  ```

- **Inspect Specific Settings**:
  ```bash
  docker inspect -f '{{.NetworkSettings.IPAddress}}' src-flask_app-1
  ```
