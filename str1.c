#include<stdio.h>
#include<string.h>
int main()
{
	char ch[10];
	char ch1[10];
	int i = 0;
	int j = 0;
	int len = 0;
	printf("Enter 1st string\n");
	fgets(ch, 10, stdin);
	*(ch + (strlen(ch) - 1)) = '\0';
	printf("Enter 2nd string\n");
	fgets(ch1, 10, stdin);
	
	while (ch[i] != '\0') {
		i++;
	}
	while (ch1[j] != '\0') {
		ch[i] = ch1[j++];
		i++;
	}
	ch[i] = '\0';
	printf("%s", ch);
}
