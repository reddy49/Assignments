#include<stdio.h>

int main()
{
	FILE *fp1;
	fp1 = fopen ("count.txt", "w+");
	char ch[100];
	int count = 0;
	int i;
	printf("Enter string\n");
	fgets(ch, 100, stdin);
	fprintf(fp1,"%s", ch);
	fseek(fp1, 0, SEEK_SET);
	while (fgetc(fp1) != EOF) {
//		if (ch[i] == ' ' && ch[i] == '\n')
		count = count + 1;
	}
	printf("%d\n", count);
//	fseek(fp1, 0, SEEK_SET);
//	fgets(ch, 100, fp1);
//	printf("%s", ch);
	fclose(fp1);
}
