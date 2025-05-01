# client/client.py
import socket
import threading

HOST = '127.0.0.1'  # or your server's IP
PORT = 9090         # must match server port

def receive_messages(sock):
    while True:
        try:
            msg = sock.recv(1024).decode()
            if msg:
                print(f"\n{msg}")
            else:
                print("Server closed the connection.")
                break
        except:
            print("Disconnected from server.")
            break

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    client_socket.connect((HOST, PORT))
    print("Connected to the chat.")
except Exception as e:
    print(f"Connection failed: {e}")
    exit()

# Start thread for receiving messages
threading.Thread(target=receive_messages, args=(client_socket,), daemon=True).start()

print("Type your messages below:")

while True:
    try:
        message = input()
        if message.lower() == 'exit':
            print("Exiting chat...")
            client_socket.close()
            break
        client_socket.send(message.encode())
    except Exception as e:
        print(f"Error while sending message: {e}")
        client_socket.close()
        break
