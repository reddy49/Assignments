#include<stdio.h>

unsigned int sbin(unsigned int num)
{
	int i;
	int count = 0;
	printf("set bits = ");
	for (i = 1 << 7; i > 0; i = i/2) {
		if (num & i) {
			printf("1");
			count = count + 1;
		}	else {
			printf("0");
			}
		}
		printf("%d\n", count);
}
unsigned int cbin(unsigned int num)
{
	int i;
	int count1 = 0;
	printf("clear bits = ");
	for (i = 1 << 7; i > 0; i = i/2) {
		if (num & i) {
			printf("1");
		}	else {
			printf("0");
			count1 = count1 + 1;
			}
		}
		printf("%d", count1);
}

int main()
{
	int num;
	printf("Enter number");
	scanf("%d", &num);
	sbin(num);
	cbin(num);
}
