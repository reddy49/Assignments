#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define SIZE 100
int main()
{
	int sfd = 0;
	int bin = 0;
	int cfd = 0;
	char buff[SIZE];
	struct sockaddr_in server;
	struct sockaddr_in client;
		server.sin_family = AF_LOCAL;
		server.sin_port = htons(1234);
		server.sin_addr.s_addr = INADDR_ANY;
		server.sin_zero[8] = '\0';
	sfd = socket(AF_LOCAL, SOCK_STREAM, 0);
	bin = bind(sfd, (struct sockaddr*)&server, sizeof(server));
	bin = listen(sfd, 5);
	int len = sizeof(client);
	cfd = accept(sfd, (struct sockaddr*)&client, &len);
	read(cfd, buff, SIZE);
	printf("The messege from client: %s\n", buff);
//	printf("Enter the message\n");
//	fgets(buff, SIZE, stdin);
	write(cfd , "hello subscribers", SIZE);
	close(cfd);
	close(sfd);
}
