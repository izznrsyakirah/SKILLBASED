#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include <sys/types.h>

int main(int argc, char * argv[]) {
int socket_desc, client_sock, c, read_size;
struct sockaddr_in server, client; 
char buffer[5];
srand(time(NULL));
int n;

socket_desc = socket(AF_INET, SOCK_STREAM, 0); 
if (socket_desc == -1)
{
printf("Could not create socket");
}
puts("Socket created");


server.sin_family = AF_INET; 
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port = htons(8080); 

if (bind(socket_desc, (struct sockaddr * ) & server, sizeof(server)) < 0) {
perror("bind failed. Error");
return 1;
}
puts("bind done");

listen(socket_desc, 3);

3


puts("Waiting for connections...");
c = sizeof(struct sockaddr_in);
if (client_sock < 0) 
{
perror("accept failed");
return 1;
}
puts("Connection accepted");

client_sock = accept(socket_desc, (struct sockaddr * ) & client, (socklen_t * ) & c);
for (int i = 0; i < 1; i++) {
bzero(buffer, 4);

if (n < 0) perror("ERROR reading from socket");

int randomNum = rand() % 900 + 100;
sprintf(buffer, "%d \n", randomNum);
n = write(client_sock, buffer, strlen(buffer));
if (n < 0) perror("ERROR writing to socket");
}
return 0;
}
