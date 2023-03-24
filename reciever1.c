#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define SIZE 100

int main()
{
	int cfd = 0;
	int bin = 0;
	int con = 0;
	char buff[SIZE];
	struct sockaddr_in client;
		client.sin_family = AF_LOCAL;
		client.sin_port = htons(1234);
		client.sin_addr.s_addr = INADDR_ANY;
		client.sin_zero[8] = '\0';
	cfd = socket(AF_LOCAL, SOCK_STREAM, 0);
	con = connect (cfd, (struct sockaddr*)&client, sizeof(client));
	write(cfd, "hello youtuber", SIZE);
	read(cfd, buff, SIZE);
	printf("The message from server: %s\n",buff);
//	printf("Enter message from client side");
//	fgets(buff, SIZE, stdin);
	close(cfd);
}
