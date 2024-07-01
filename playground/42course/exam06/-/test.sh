#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <server_ip> <port> <number_of_clients>"
    exit 1
fi

SERVER_IP=$1
PORT=$2
NUM_CLIENTS=$3
TIMEOUT=5
SUCCESS_COUNT=0
FAIL_COUNT=0

# Function to check server reachability
check_server() {
    if nc -z -w$TIMEOUT $SERVER_IP $PORT 2>/dev/null; then
        echo "Server at $SERVER_IP:$PORT is reachable."
        return 0
    else
        echo "Error: Server at $SERVER_IP:$PORT is not reachable."
        echo "Debugging information:"
        echo "- Trying to connect using nc:"
        nc -v -w$TIMEOUT $SERVER_IP $PORT
        echo "- Checking localhost:"
        nc -z -w$TIMEOUT localhost $PORT && echo "localhost:$PORT is reachable" || echo "localhost:$PORT is not reachable"
        echo "- Checking 127.0.0.1:"
        nc -z -w$TIMEOUT 127.0.0.1 $PORT && echo "127.0.0.1:$PORT is reachable" || echo "127.0.0.1:$PORT is not reachable"
        return 1
    fi
}

# Check if server is reachable
if ! check_server; then
    exit 1
fi

connect_client() {
    local client_num=$1
    local message="Hello from Client $client_num"

    (
        echo "Client $client_num attempting to connect..."
        exec 3<>/dev/tcp/$SERVER_IP/$PORT
        if [ $? -eq 0 ]; then
            echo "$message" >&3
            echo "Client $client_num connected and sent message."
            # Keep the connection open
            cat <&3 > /dev/null &
            echo $! > /tmp/client_$client_num.pid
            exit 0
        else
            echo "Client $client_num failed to connect or send message."
            exit 1
        fi
    )
}

for i in $(seq 1 $NUM_CLIENTS); do
    connect_client $i &
    pid=$!
    if wait $pid; then
        ((SUCCESS_COUNT++))
    else
        ((FAIL_COUNT++))
    fi
done

echo "All clients connected. Press Enter to disconnect all clients."
read

# Disconnect all clients
for i in $(seq 1 $NUM_CLIENTS); do
    if [ -f /tmp/client_$i.pid ]; then
        kill $(cat /tmp/client_$i.pid) 2>/dev/null
        rm /tmp/client_$i.pid
        echo "Client $i disconnected."
    fi
done

echo "Test completed."
echo "Successful connections: $SUCCESS_COUNT"
echo "Failed connections: $FAIL_COUNT"

if [ $FAIL_COUNT -eq 0 ]; then
    echo "All clients connected successfully and were disconnected."
    exit 0
else
    echo "Some clients failed to connect properly."
    exit 1
fi
