#include<stdio.h>
int main()
{
	unsigned char n = 0xab;
	unsigned char c;
	c = ((n>>4) | (n<<4));
	printf("%x", c);
}
