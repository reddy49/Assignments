#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void segfault_handler(int signal_number) {
	int i = 0;
	printf("Signal caugth%d\n", i);
	i++;
}
int main()
{
	signal(SIGSEGV,segfault_handler);
	int *p = 0;
	*p = 42;
}

