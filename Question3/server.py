import random
import socket
import threading

quotes = [
"I never dreamed about success. I worked for it",
"Keep your head up",
"Loost time is never found again",
]

def handle_client(client_socket):
client_socket.send(random.choice(quotes).encode())
client_socket.close()

def main():

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('192.168.56.1', 8888))
server_socket.listen()

while True:
client_socket, client_address = server_socket.accept()
client_thread = threading.Thread(target=handle_client, args=(client_socket,))
client_thread.start()

if __name__ == '__main__':
main()
