import socket

# IP address and port of the NodeMCU
SERVER_IP = '172.20.10.2'  # Replace 'NodeMCU_IP_Address' with the actual IP address of your NodeMCU
SERVER_PORT = 12345  # Choose a port number, make sure it matches the one used in the NodeMCU code

# Message to send
message = "hi"

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server (NodeMCU)
client_socket.connect((SERVER_IP, SERVER_PORT))

# Send the message
client_socket.send(message.encode())

# Close the socket
client_socket.close()
