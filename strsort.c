#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
int main()
{
	char **ptr;
	int size;
	int i;
	int j;
	char *temp;
	printf("Enter how many names you want");
	scanf("%d", &size);
	ptr = (char **) malloc (size * sizeof(char *));

	for (i = 0; i <= size; i++) {
		*(ptr + i) = (char *) malloc (SIZE * sizeof(char));
	}
//	printf("Enter name\n");
	for (i = 0; i <= size; i++) {
		printf("Enter name\n");
		fgets(*(ptr + i), SIZE, stdin);
	}
	for (i = 0; i <= size; i++) {
		printf("elements is :%s", *(ptr + i));
	}
	for (i = 0; i <= size; i++) {
		for (j = i + 1; j <= size; i++) {
			if (*(*(ptr + i)) > *(*(ptr + j))) {
				temp = *(ptr + i);
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = temp;
			}
		}
	}
	printf("sorted elements is:\n");
	for ( i = 0; i <= size; i++) {
		printf("%s", *(ptr + i));
	}
}
		
