#include<stdio.h>

int main()
{
	unsigned int i = 12;
	char c = (char)&i;
	for(unsigned int j = 1<<31;i>0;i = i>>1) {
		if(j & i) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
/*	for(unsigned int j = 1<<7;i>0;i = i>>1) {
		if(j & c) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");*/
	if(c) {
		printf("little endian");
	} else {
		printf("big endian");
	}
}
