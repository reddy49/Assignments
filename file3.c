// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
extern int errno;
int main()
{	
	int n,f;
	char buf[6];
	int fd = open("foo1.txt",O_RDWR);
//	printf("%d", fd);
	read(fd, buf, 6);
	write(1, buf, 6);
	lseek(f, 5, SEEK_CUR);
	read(f, buf, 6);
	write(1, buf,6);
}
	
