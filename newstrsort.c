
#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100
#if 1
int main()
{
        char **ptr;
        int size;
        int i;
        int j;
        char *temp;
        printf("Enter how many names you want");
        scanf("%d", &size);
		__fpurge(stdin);
        ptr = (char **) malloc (size * sizeof(char *));

        for (i = 0; i < size; i++) {
                *(ptr + i) = (char *) malloc (SIZE * sizeof(char));
        }

        for (i = 0; i < size; i++) {
                printf("Enter name\n");
                fgets(ptr[i], SIZE, stdin);
        }
        for (i = 0; i < size; i++) {
                printf("elements is :%s", *(ptr + i));
        }
        for (i = 0; i < size - 1; i++) {
                for (j = i + 1; j < size ; j++) {
                        if (*(ptr + i) < *(ptr + j)) {
                                temp = *(ptr + i);
                                *(ptr + i) = *(ptr + j);
                                *(ptr + j) = temp;
                        }
                }
        }
		printf("sorted elements is:\n");
        for ( i = 0; i < size; i++) {
                printf("%s", *(ptr + i));
        }
}
#endif

#if 0
int main() 
{
	int size = 0;
	int i;
	
	printf("Enter how may names you want - \n");
	scanf("%d", &size);
	__fpurge(stdin);
	char**ptr = (char**) malloc(size * sizeof(char*));
	for(i = 0; i < size; i++) {
		*(ptr + i) = (char*) malloc(SIZE * sizeof(char));
	}

	for(i = 0; i < size; i++) {
		printf("Enter name %d -\n", i + 1);
		fgets(*(ptr + i), SIZE, stdin);
	}

	for(i = 0; i < size; i++) { 
		printf("%s\n",*(ptr + i));
	}

	return 0;
}
#endif
