#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
#if 0
int main()
{
	int **ptr;
	ptr = (int **) malloc (sizeof(int*));
	*ptr = (int *) malloc (sizeof(int));
	printf("ptr = %p\n", ptr);
	printf("*ptr = %p\n", *ptr);
	printf("**ptr = %d", *(*ptr));
}
#endif
#if 1
int main()
{
	int *ptr;
	ptr = (int *) malloc (SIZE * (sizeof(int)));
	printf("Enter the size");
	scanf("%d", &SIZE);
	printf("Enter elements");
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", (ptr + i));
	}
	printf("Elements is:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d", *(ptr + i));
	}
}
#endif
