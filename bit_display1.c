#include<stdio.h>
int bin(int n)
{
	int i;
	for (i = 1 << 7; i > 0; i = i >> 1) {
		if(n & i) {
	    	printf("1");
	    } else {
	        	printf("0");
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	bin(n);
	return 0;
}
