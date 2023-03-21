#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
extern int errno;
int main()
{	
	char *ch = (char *) malloc (SIZE * sizeof(char));
	int sz;
	ch = "sumanth";
	int fd = open("fooo.txt", O_RDONLY | O_CREAT);
	printf("fd = %d\n", fd);
	if (fd > 0) {
		printf("Failed");
		exit(1);
	}
	sz = read(fd, ch ,10);
	sz = write(fd,fgets(ch, SIZE, stdin), sz);
 	printf("%d " " %ld" "%d", fd, strlen(ch), sz);
	close(fd);

//	printf("%d , ch , 10 " "%d \n", fd, sz);
	ch[sz] = '\0';
	printf("%s\n", ch);
	return 0;
}

