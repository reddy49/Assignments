#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
	pid_t pid;
	pid = fork();
	printf("%d\n", getpid());
	//getchar();
	if (pid == 0) {
		//while(1);
		printf("child %d\n", getpid());
		exit(1);
	} else {
		getchar();
		printf("Parent %d\n", getpid());
		while (1);
	}
}
