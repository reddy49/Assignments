#include <stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	fp = fopen("arr_str.txt", "r+");
	char **ch = (char **) malloc(10 * sizeof(char*));
	for (int i = 0;i <3;i++) {
		*(ch + i) = (char *) malloc (10 * sizeof(char));
	}
	printf("enter strings");
	for (int i = 0;i<3;i++) {
		scanf("%s", *(ch+i));
	}
	for (int i = 0;i<3;i++) {
		fprintf(fp,"%s",ch[i]);
	}
	fclose(fp);
}
