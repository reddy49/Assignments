#include<stdio.h>

int prime(int n,int i);
int count = 0;
int main()
{
	int n;
	int i = 1;
	printf("Enter number");
	scanf("%d", &n);
	prime(n, i);
	if (count == 2) {
		printf("Num is prime");
	} else {
		printf("not prime");
	}
}
int prime(int n,int i)
{
	if(i <= n) {
		if(n % i == 0) {
			count++;
		}		
	prime (n, i + 1);
	}
	return count;
}
