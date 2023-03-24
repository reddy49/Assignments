#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
int str_cpy(char *str, char *str1);
int main()
{
	char *str = NULL;
	char *str1 = NULL;
	str = ((char *) malloc (SIZE * sizeof(char)));
	str1 = ((char *) malloc(SIZE * sizeof(char)));
	if ( NULL == str && NULL == str1) {
		printf("malloc failed!\n");
		exit(0);
	}
	printf("Enter first string");
	if (NULL == (fgets(str, SIZE, stdin))) {
		printf("Fgets failed for str");
	}
	printf("Enter second string");
	if (NULL == (fgets(str1, SIZE, stdin))) {
		printf("Fgets failed for str2");
	}
	*(str + (strlen(str)) - 1) = '\0';
	*(str1 + (strlen(str)) - 1) = '\0';
	int res = str_cpy(str, str1);
	if (res == 1) 
		printf("strings are equal");
	else 
		printf("str is greater than str1");
//	else
//		printf("str is less tham str2");
	free(str);
	free(str1);
	str = NULL;
	str1 = NULL;	
}

int str_cpy(char *str, char *str1)
{
	int flag = 0;
	while (*str != '\0' && *str1 != '\0') {
		if (*str == *str1) {
			flag = 0;
			break;
//		else if (*str != *str1) {
//			flag = 1;
//			break;
//		}
		}
		str++;
		str1++;
	}
	if (flag == 0 && *str == '\0' && *str1 == '\0') 
		return 0;
	else if (*str > *str1)
		return 1;
	else 
		return -1;
	
}








/*	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	int length1 = 0;
	while (str1[length1] != '\0') {
		length1++;
	}

	int i =0;
	while (str[i] == str1[i] && str[i] != '\0') {
		i++;
	
	if (strlen(str) == strlen(str1)) {
		return 0;
	//	printf("Both are equal");
	}
	else if (strlen(str) > strlen(str1)) {
		return 1;
	//	printf("Str is greater than str2");
	}
	else  
		return -1;
	//	printf("str is less than str2");
	}
}
*/	





