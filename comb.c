#include<stdio.h>

int main() {
	unsigned int n;
	printf("enter number");
	scanf("%d", &n);
	unsigned int i;
	int c = 0;
	unsigned int x = 1 << 31;
	for(i = 32; i > 0 ;i--) {
		if(n & x) {
			c++;
			if(c == 3) {
				n = n ^ (1 << (i - 1));
				c = 0;
			}
		} else {
			c = 0;
		}
		x = x>>1;
	}
	printf("%d ", n);
	for(i = 1<<7;i>0;i = i>>1) {
		if(n & i) {
			printf("1");
		} else {
			printf("0");
		}
	}
}
