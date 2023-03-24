#include<stdio.h>
#include <string.h>

int main() 
{ 
	char ch[10];
	char *ptr = ch;
	printf("enter str : ");
	scanf("%s",ch);
	printf("%s\n",ch);
	int len = strlen(ch);
	printf("len : %d\n", len);
	printf("char : %c", *(ptr + 9));
	
}
