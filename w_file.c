#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
int main()
{
	FILE *fp1;
	char ch[100][100];
//	ch = (char *) malloc (SIZE * sizeof(char));
	fp1 = fopen ("su.txt", "w+");
	printf("Enter  a string");
	for (int i = 0; i < 3; i++) {
		fgets(ch[i], 100, stdin);
		fprintf(fp1, "%s", ch[i]);
	}
//	fscanf(fp1, "%s", ch);
//	fgets(ch, 10, fp1);
//	printf("%s", ch);
	fseek(fp1, 0, SEEK_SET);
//	fscanf(fp1, "%s", ch);
	for (int i = 0; i < 3; i++) {
		fgets(ch[i], 100, fp1);
		printf("%s", ch[i]);
	}
	fclose(fp1);
	return 0;
}

