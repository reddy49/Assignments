#include<stdio.h>

int main()
{
	unsigned int n;
	printf("Enter number");
	scanf("%d", &n);
	int i = 0;
	int t = n;
	int c = 0;
	int count = 0;
	while (i < n) {
		if(t & (1 << c)) { 
			count++;
		}
		c++;
		n = n>>1;
	}
	printf("%d", count);
}
