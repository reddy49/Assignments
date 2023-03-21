#include<stdio.h>

int main()
{
	unsigned short num = 0xAB;
	unsigned short res;
	res = ((num >> 4) | (num << 4));
	printf("%x", res);
}
