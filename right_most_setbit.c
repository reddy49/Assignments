#include<stdio.h>

int bin(unsigned int num)
{
	int i;
	for (i = 1<<7; i > 0;i = i>>1) {
		if (num & i) {
			printf("1");
		} else { 
			printf("0");
		}
	}
	printf("\n");
}

int clear_right(unsigned int num)
{
	num = num & (num - 1);
	bin(num);
}
int clear_left(unsigned int num)
{
	num = num & (num - 128);
	bin(num);
}
int main()
{
	unsigned int num;
	printf("Enter number");
	scanf("%d", &num);	
	bin(num);
	clear_right(num);
	clear_left(num);
}
	
