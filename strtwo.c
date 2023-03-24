#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
int main() 
{
	int size;
	int i;
	
//	printf("Enter how may names you want - \n");
//	scanf("%d", &size);
//	__fpurge(stdin);
	char**ptr = (char**) malloc(SIZE * sizeof(char*));
	for(i = 0; i < 2; i++) {
		*(ptr + i) = (char*) malloc(SIZE * sizeof(char));
	}

	for(i = 0; i < 2; i++) {
		printf("Enter name %d -\n", i + 1);
		fgets(*(ptr + i), SIZE, stdin);
	}
	

	for(i = 0; i < 2; i++) { 
		printf("%c\n", *(*(ptr + i) + 1));
	}
}

