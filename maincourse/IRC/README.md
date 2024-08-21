# ft_irc - Internet Relay Chat Server

**ft_irc** is a project focused on building an IRC (Internet Relay Chat) server in C++98. The project requires handling multiple clients, managing channels, and implementing basic IRC commands. The goal is to develop a solid understanding of socket programming, TCP/IP communication, and non-blocking I/O operations.

## Project Overview

This project involves:
- Creating a fully functional IRC server using C++98.
- Handling multiple clients simultaneously without forking.
- Implementing a subset of essential IRC features such as channels, messaging, and operator commands.
- Ensuring non-blocking I/O using `poll()` or an equivalent method.

The server should work similarly to a real IRC server, allowing you to connect with an actual IRC client for testing.

## Features

- **Client Handling**: The server can handle multiple clients simultaneously.
- **TCP/IP Communication**: All client-server communication is done via TCP (IPv4/IPv6).
- **Channel Management**: Supports public and private channels with operator privileges.
- **Authentication**: Clients must provide a password to connect to the server.
- **Basic IRC Commands**:
    - **NICK**: Set a nickname for the client.
    - **USER**: Register a username.
    - **JOIN**: Join a channel.
    - **PRIVMSG**: Send private messages to users or channels.
    - **Operator Commands**:
        - **KICK**: Remove a client from a channel.
        - **INVITE**: Invite a client to a channel.
        - **TOPIC**: Set or view the channel’s topic.
        - **MODE**: Change channel settings (e.g., invite-only, password, operator status).

## Requirements

- **Language**: C++98
- **External Libraries**: None (No Boost, external libraries, or additional dependencies)
- **System Compatibility**: Unix-based systems (with special instructions for macOS)
- **Build**: The project is compiled using a Makefile with the standard rules: `all`, `clean`, `fclean`, `re`.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/ft_irc.git
    cd ft_irc
    ```

2. Compile the project:
    ```bash
    make
    ```

3. Run the server:
    ```bash
    ./ircserv <port> <password>
    ```
    - **port**: The port number for incoming connections.
    - **password**: The connection password required by clients.

## Usage

1. Connect to the server using an IRC client:
    ```bash
    irssi -c 127.0.0.1 -p <port> -w <password>
    ```
2. Interact with the server using standard IRC commands like `/nick`, `/join`, `/msg`, etc.

## Bonus Features

If the mandatory features are completed perfectly, you can implement:
- **File Transfer**: Allow clients to send files through the IRC server.
- **Bot**: Create an automated bot that responds to commands or messages.

## Project Structure

```
IRC/
├── -           # Miscellaneous files
├── Makefile    # Build instructions
├── README.md   # Project documentation
├── inc         # Header files
└── src         # Source files
```

## Testing

You can test the server using tools like `netcat` (nc):
```bash
nc 127.0.0.1 <port>
```

You can also use a real IRC client like `irssi` or `WeeChat` for more extensive testing.

## Contributing

Feel free to open issues or submit pull requests for improvements. Contributions should follow the C++98 standard and maintain compatibility with the project guidelines.

## License

This project is licensed under the MIT License.

## Acknowledgments

This project is part of the 42 curriculum and is designed to deepen understanding of network programming and C++.
