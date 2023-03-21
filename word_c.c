#include<stdio.h>

int main()
{
	FILE *fp1;
	char ch[100];
	int word = 0;
	int i;
	fp1 = fopen ("word.c", "w+");
	printf("Enter string");
	fgets(ch, 100, stdin);
	fprintf(fp1, "%s", ch);
	fseek(fp1, 0, SEEK_SET);
	while ((ch[i] = fgetc(fp1)) != EOF) {
		if (ch[i] == ' ' || ch[i] == '\n') 
			word++;
	}
	printf("%d", word);
	fseek(fp1, 0, SEEK_SET);
	fgets(ch, 100, fp1);
	printf("%s", ch);
	fclose(fp1);
}
