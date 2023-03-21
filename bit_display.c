#include<stdio.h>

int main(void)
{
   	int i;
	unsigned char n;
	scanf("%hhi", &n);
	for (i = 128; i > 0; i = i/2){
		if(n & i) {
	    	printf("1"); 
	    } else {
	        printf("0");
			}
	}
}
