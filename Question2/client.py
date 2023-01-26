import socket

	def main():

	client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	client_socket.connect((“127.0.0.1”, 8888))

	fahrenheitcelc = input(“Enter temp fahrenheit: “)
	client_socket.send(fahrenheitcelc.encode())

	temp_celcius = client_socket.recv(1024)
	temp_celcius = float(temp_celcius.decode())

	print(“Temperature in celsius: % temp_celcius)
	client_socket.close()

	main()
