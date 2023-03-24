#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
int main()
{
	char *str;
	char ch;
	int pos;
	str = (char *) malloc (SIZE * sizeof(char));
	printf("Enter string");
	fgets(str, 20, stdin);
	printf("Enter char");
	scanf("%c", &ch);
	printf("Enter pos");
	scanf("%d", &pos);
	int i;
	for(i = strlen(str); i > 0; i--) {
		*((str + i) + 1) = *(str + i);
		if (i == pos) {
		  *(str + i) = ch;
		break;
		}
	}
	printf("%s",(str + i));
}
