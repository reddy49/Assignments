#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

char *strrev(char *str);

int main()
{
	char *str = NULL;
	str = (char *) malloc (SIZE * (sizeof(char)));
	if (str == NULL) {
		printf("malloc is failed"); 
		exit(0);
	}
	printf("Enter the string");
	if (NULL == (fgets(str, SIZE, stdin))) {
		printf("fgets is failed");
	}
	*(str + (strlen(str) - 1)) = '\0';
	printf("%s", strrev(str));
	free(str);
	str = NULL;
}
char *strrev(char *str)
{
	int flag;
	char *temp = str;
	int len = strlen(str);
	char *res = str + len - 1;
	char *rev = str;
	while (res > rev) {
		*res = *res + *rev;
		*rev = *res - *rev;
		*res = *res - *rev;
		res--;
		rev++;
	}
	return str;
}	
