#include<string.h>
#include<sys/socket.h> 
#include<arpa/inet.h> 
#include<unistd.h> 
int main(int argc, char * argv[]) {
int sock;
struct sockaddr_in server;
char message[2000], server_reply[3000];

sock = socket(AF_INET, SOCK_STREAM, 0);
if (sock == -1) {
printf("Error to create socket");
}
puts("Socket has been created");
server.sin_addr.s_addr = inet_addr("10.0.0.15"); 
server.sin_family = AF_INET;
server.sin_port = htons(8080); 

if (connect(sock, (struct sockaddr * ) & server, sizeof(server)) < 0) {
perror("connect failed. Error"); 
return 1;
}
puts("Socket Connected\n");

for (int i = 0; i < 1; i++) { 

if (send(sock, message, strlen(message), 0) < 0) {
puts("Send failed");
return 1;
}

if (recv(sock, server_reply, 2000, 0) < 0) {
puts("received failed");
break;
}
printf("\n %s \n", server_reply);

}
close(sock);
return 0;
}
