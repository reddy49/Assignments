#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
int main()
{
	char **ptr;
	int size;
	int i;
	printf("Enter how many names you want");
	scanf("%d", &size);
	ptr = (char **) malloc (size * (sizeof(char *)));
	printf("Enter names");
	for (i = 0; i <= size; i++) {
		*(ptr + i) = (char *) malloc (SIZE * (sizeof(char)));
		fgets(*(ptr + i), SIZE, stdin);
	}
	for (i = 0; i <= size; i++) {
		printf("%s", *(ptr + i));
	}
}
	
