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
 1. [X] Check arguments
 2. [X] Create socket and check for errors
 3. [X] Assign ip and port to servaddr (port = argv[1])
 4. [X] Bind the socket to the ip and port
 5. [X] Listen for incoming connections
 6. [X] Initialize the file descriptor set
 7. [X] Add the server file descriptor to the set and update maxfd
 8. [X] Start the main loop
 9. [X] Copy the current file descriptor set
10. [X] Check if any file descriptors are ready for reading
11. [X] Check all file descriptors
12. [X] If a new client is trying to connect(accept)
13. [X] If the connection was successful, update maxfd and add the client file descriptor to the set
14. [X] Send a message to all clients that a new client has connected
15. [X] If a client is trying to send a message
16. [X] Receive the message
17. [X] If the message was received successfully, send the message to all clients
18. [X] If the client has disconnected
19. [X] Send a message to all clients that a client has disconnected
20. [X] Remove the client file descriptor from the set
21. [X] Close the file descriptor
22. [X] End of main loop
*/
