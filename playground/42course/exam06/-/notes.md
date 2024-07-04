Linux
[+] David
[-] Clement
[-] Rossi

MacOS
[-] David
[-] Clement
[-] Rossi
[ ] davidszkl

/*
[X] Check arguments
[X] Create socket
[X] Assign IP and port
[X] Bind the socket
[X] Listen for incoming connections
[X] Initialize fd_set (FD_ZERO)
[X] Add socket fd to currentfd (FD_SET)
[X] Update maxfd with socketfd

[X] Start the main loop
[X] Copy currentfd to readfd
![X] Check if any fd are ready for reading (syscall: select)
![X] Check all file descriptors
![X] Check if fd is not in the readfd set, then skip it (syscall: continue).
[X] Iterate over all fds and check
[ ] If sockfd = fd (new client)
    [X] Accept a connection with a new client (syscall: accept)
[ ] Update maxfd
[ ] Add the client file descriptor to a set
[ ] Send a message to all clients that a new client has connected
[ ] Else if a client is trying to send a message
[ ] Receive the message
[ ] If the message was received successfully, send the message to all clients
[ ] If the client has disconnected (syscall: recv)
[ ] Send a message to all clients that a client has disconnected
[ ] Remove the client file descriptor from the set
[ ] Close the file descriptor
[ ] End of main loop
*/
