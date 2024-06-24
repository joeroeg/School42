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
1. Check arguments
2. Create socket and check for errors
3. Assign ip and port to servaddr
4. Bind the socket to the ip and port
5. Listen for incoming connections
6. Initialize the file descriptor set
7. Add the server file descriptor to the set
8. Start the main loop
9. Copy the current file descriptor set
10. Check if any file descriptors are ready for reading
11. Check all file descriptors
12. If a new client is trying to connect(accept)
13. If the connection was successful, update maxfd and add the client file descriptor to the set
14. Send a message to all clients that a new client has connected
15. If a client is trying to send a message
16. Receive the message
17. If the message was received successfully, send the message to all clients
18. If the client has disconnected
19. Send a message to all clients that a client has disconnected
20. Remove the client file descriptor from the set
21. Close the file descriptor
22. End of main loop
*/
