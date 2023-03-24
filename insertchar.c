#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
char *my_strcpy(char *, char , int );
int main()
{
	char *str = NULL;
	char ch;
	int pos;
	str = ((char *) malloc (SIZE * sizeof(char)));
	if ( NULL == str) {
		printf("malloc failed!\n");
		exit(0);
	}
	printf("Enter first string");
	if (NULL == (fgets(str, SIZE, stdin))) {
		printf("Fgets failed for str");
	}
	*(str + (strlen(str)) - 1) = '\0';
	printf("Enter insert char");
	scanf("%c", &ch);
	printf("Enter pos");
	scanf("%d", &pos);
	printf("%s", my_strcpy(str, ch, pos));
	free(str);
	str = NULL;
	return 0;
}
char *my_strcpy(char *str, char ch, int pos)
{
	char *str1= str;
	char temp;
	int i = 1;
	while (*str != '\0') {
		if (i == pos) {
			temp = *str;
			*str = ch;
			ch = temp;
			pos++;
		}
		*str++;
		i++;
	}
	return *str1;
}
