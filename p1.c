#include<stdio.h>
void TOH(int,char,char,char);
int main()
{
	int n;
	char a,b,c;
	printf("enter n value:");
	scanf("%d",&n);
	TOH(n,'a','b','c');	
}
void TOH(int n,char a,char b,char c)
{
//	else if(n==1)
//	{
/*	 printf("|     |     |     |\n"
            "|     |     |     |\n"
            "|     |     |     |\n"
            "|     |     |     |\n"
            "|  %c  | %c   |  %c  |\n"
            "rod a  rod b  rod c\n",a,b,c);*/	
		//	}
	if(n>0)
	{
		TOH(n-1,a,c,b);
	//	TOH(1,a,b,c);
		printf("move disc from %c to %c\n",a,c);

		TOH(n-1,b,a,c);
		
	}
}
