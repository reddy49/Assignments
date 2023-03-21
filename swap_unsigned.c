#include<stdio.h>
int bin(unsigned int num);
int swap_bits_within(unsigned int num, unsigned int s, unsigned int d);
int main()
{
	unsigned int num;
	unsigned int s;
	unsigned int d;
	printf("Enter the number");
	scanf("%d", &num);
	printf("Enter the source");
	scanf("%d", &s);
	printf("Enter the destination");
	scanf("%d", &d);
	bin(num);
	swap_bits_within(num, s, d);
}
int bin(unsigned int num)
{
	int i;
	for (i = 1 << 7; i > 0; i = i/2) {
		if (num & i ) {
			printf("1");
		} else {
			printf("0");
			}
	}
}

int swap_bits_within(unsigned int num, unsigned int s, unsigned int d)
{
	int i;
	if ((num & ( 1 << s) ) && (num & (1 << d))) {
		printf("No need to swap");
	} else {
		num ^= (1 << s) | (1 << d);
		printf(" %i\n",num);
		bin(num);
		}
}

