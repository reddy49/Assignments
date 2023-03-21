#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000
int main()
{
	FILE *fp1;
	char ch;
	fp1 = fopen ("1_100.txt", "w+");
	printf("numbers is  ");
	for (ch = 1; ch < 100; ch++) {
		fprintf(fp1, "%d", ch);
	}
	fseek(fp1, 0, SEEK_SET);
	for (ch = 1; ch < 100; ch++) {
		printf("%d", ch);
	}
	fclose(fp1);
	return 0;
}

