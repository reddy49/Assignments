#include<stdio.h>

int main()
{
	FILE *fp1;
	char ch[100];
	int word = 0;
	int i = 0;
	char z;
	char ch1;
	ch1 = 'k';
	fp1 = fopen ("word.txt", "w+");
	printf("Enter string");
	fgets(ch, 10, stdin);
	fprintf(fp1, "%s", ch);
	fseek(fp1, 0, SEEK_SET);
	while ((z = fgetc(fp1)) != EOF) {
		if (z == 'a') {
			fseek(fp1,-1,SEEK_CUR);
			fputc(ch1,fp1);
			
		}
	}
	fseek(fp1, 0, SEEK_SET);
	fgets(ch, 100, fp1);
	printf("%s", ch);
	fclose(fp1);
}
