#include<stdio.h>

unsigned int bin(unsigned int n)
{
	int i;
	printf("num = ");
	for (i = 1 << 7; i > 0; i = i/2) {
		if (n & i) {
			printf("1");
		} else {
			printf("0");
			}
	}
}

unsigned int toggle_even(unsigned int n)
{
	int res = 0;
	int count = 0;
	int i;
	for(i = n; i > 0; i >>= 1) {
		if (count % 2 == 0) 
			res |= (1 << count);
			count++;
			
	}
	bin(n);
	res = n ^ res;
//	return res;
//	printf("%d\n", bin(n));
//	bin(n);
}

int main()
{
	int n;
	printf("Enter number");
	scanf("%d", &n);
//	int count;
//	int res;
//	bin(n);
	printf("%d", toggle_even(n));
	return 0;
}
