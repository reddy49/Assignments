#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
int main()
{
	char *str1;
	char *str2;
	str1 = (char *) malloc (SIZE * sizeof(char));
	str2 = (char *) malloc (SIZE * sizeof(char));
	printf("Enter string 1");
	fgets(str1, SIZE, stdin);
	printf("Enter string 2");
	fgets(str2, SIZE, stdin);
	int i = 0;
	int j = 0;
	int flag = 0;
	int count = 0;
	char *temp = str2;
	while (*str1  != '\0') {
		temp = str2;
		while (*temp != '\0') {
			if (*str1 == *temp) {
			 	flag = 1;
				break;
			}
			temp++;
		}
		if (flag == 1) {
			break;
		}
		str1++;
		count = count + 1;
	}
	printf("count= %d", count);
}
