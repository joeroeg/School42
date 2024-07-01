#!/bin/bash

server="127.0.0.1"  # Replace with your server's IP or hostname
port="8080"       # Replace with the port number

message="Hello!"

echo "$message" | nc "$server" "$port"
