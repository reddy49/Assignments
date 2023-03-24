#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void sig_handler(int signum)
{
	printf("caught Sigint %d\n",signum);
}
int main()
{
	signal(SIGINT,sig_handler);
	while(1) {
		printf("program is running\n");
		sleep(1);
	}
	return 0;
}

