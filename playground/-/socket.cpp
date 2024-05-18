#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdexcept>

class Socket {
public:
    Socket() {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            throw std::runtime_error("Socket creation failed");
        }
    }

    ~Socket() {
        if (sockfd >= 0) {
            close(sockfd);
        }
    }

    void connect(const char* ip, int port) {
        struct sockaddr_in servaddr;
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(port);

        if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
            throw std::runtime_error("Invalid address/Address not supported");
        }

        if (::connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
            throw std::runtime_error("Connection failed");
        }
    }

private:
    int sockfd;
};

int main() {
    try {
        Socket sock;
        const char* google_ip = "142.250.72.238";  // One of Google's IP addresses
        int port = 80;  // HTTP port

        sock.connect(google_ip, port);
        std::cout << "Connected to Google at " << google_ip << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
