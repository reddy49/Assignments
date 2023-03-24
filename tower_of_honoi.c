#include<stdio.h>
void TOH(int,char,char,char);
int main()
{
	int n;
	char a,b,c;
	printf("enter n value:");
	scanf("%d",&n);
	printf("tower of hanoi of %d discs\n",n);
	TOH(n,'a','b','c');	
}
void TOH(int n,char a,char b,char c)
{
	if(n==0)
	printf("do nothing");
	else if(n==1)
	printf("move disc from %c to %c\n",a,c);
	else
	{
		TOH(n-1,'a','c','b');
		TOH(1,'a','b','c');
		TOH(n-1,'b','a','c');	
	}
}

