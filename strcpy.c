#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

char *my_strcpy(char *dest, char *src);

int main()
{
	char *src = NULL;
	char *dest = NULL;
	src = (char *) malloc (SIZE * (sizeof(char)));
	dest = (char *) malloc (SIZE * (sizeof(char)));
	if (src == NULL) {
		printf("malloc is failed"); 
		exit(0);
	}
	printf("Enter the string");
	if (NULL == (fgets(src, SIZE, stdin))) {
		printf("fgets is failed");
	}
	printf("%s", my_strcpy(src, dest));
	free(src);
	src = NULL;
}
char *my_strcpy(char *dest, char *src)
{
	while (*src != '\0') {
		*dest = *src;
		*src++;
		*dest++;
	}
	printf("\n%s", dest);
	return dest;
}
