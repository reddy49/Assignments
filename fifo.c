#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

int main()
{
	int res;
	res = mkfifo("fifo",0777);
	printf("Fifo is created");
}
