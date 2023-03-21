#include <stdio.h>

#define SET(NUM,P) (NUM |=  (1<<P))
#define CLR(NUM,P) (NUM &= ~(1<<P))

int main()
{
	unsigned char num;
	unsigned char p;
	
	printf("num =");
	scanf("%hhd", &num);
	printf("pos =");
	scanf("%hhd", &p);
	SET(num, p);
	printf("num = %d\n", num);
	CLR(num, p);
	printf("pos = %d\n", num);	
}
