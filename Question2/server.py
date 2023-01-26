import socket 

	def fahrenheitcelc(fahrenheit):
	
	temp_celcius = (fahrenheit - 32) * (5/9)
	return temp_celcius

	server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	
	server_socket.bind((host, port))

	server_socket.listen(1)
	print(“Waiting for the client”)

	while True: 

	connection, address = server_socket.accept()
print(‘ Got a connection from has been established ‘ % str(address))

fahrenheitcelc = connection.recv(1024).decode()
temp_celcius = fahrenheitcelc(float(fahrenheit))
temp_celcius = round(temp_celcius, 2)
temp_celcius = str(temp_celcius)
connection.send(temp_celcius.encode())

connection.close()

main()
