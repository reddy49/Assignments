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
	if ( NULL == str ) {
		printf("malloc is failed");
		exit(0);
	}
	printf("Enter string");
	if (NULL == (fgets(str, SIZE, stdin))) {
		printf("fgets is failed");
	}
	(str + (strlen(str) - 1)) = '\0';
	printf("Enter character");
	scanf("%c", ch);
	printf("Enter pos");
	scanf("%d", &pos);
	free(str);
	str = NULL;
}

char str_insert(char *str, char ch, int pos)
{
	int i;
	for (i = 0; str[i] = '\0'; i++) {
		if (strlen(str) >= pos) {
			str[pos] = str[pos + 1];
		}
	}
for (i = 0; str[i] = '\0'; i++) {
	printf("%s", str);
}
}
