#include<stdio.h>
int sbin(unsigned int snum);
int dbin(unsigned int dnum);
int swap_bits_within(unsigned int snum, unsigned int dnum, unsigned int s, unsigned int d);
int main()
{
	unsigned int snum;
	unsigned int dnum;
	unsigned int s;
	unsigned int d;
	printf("Enter the snum");
	scanf("%d", &snum);
	printf("Enter the source");
	scanf("%d", &s);
	printf("Enter the dnum");
	scanf("%d", &dnum);
	printf("Enter the destination");
	scanf("%d", &d);
	sbin(snum);
	dbin(dnum);
	swap_bits_within(snum, dnum, s, d);
}
int sbin(unsigned int snum)
{
	int i;
	printf("snum = ");
	for (i = 1 << 7; i > 0; i = i/2) {
		if (snum & i) {
			printf("1");
		} else {
			printf("0");
			}
	}
}
int dbin(unsigned int dnum)
{
	int i;
	printf("\ndnum = ");
	for (i = 1 << 7; i > 0; i = i/2) {
		if (dnum & i) {
			printf("1");
		} else {
			printf("0");
			}
	}
}


int swap_bits_within(unsigned int snum, unsigned int dnum, unsigned int s, unsigned int d)
{
	int i;
	if ((snum & (( 1 << s))) && (dnum & (1 << d))) {
		printf("No need to swap");
	} else {
		snum ^= (1 << s); 
		dnum ^= (1 << d);
		printf("\ns = %d\nd = %d\n",snum, dnum);
		sbin(snum);
		dbin(dnum);
		}
}

