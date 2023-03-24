#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char *remove_spaces(char *);
int main() {
	char *str = (char *) malloc (30 * sizeof(char));// = "  sumanth  ";
	printf("Enter string");
//	scanf("%s", str);
	fgets(str, 30,stdin);
	*(str + strlen(str) - 1) = '\0';
	printf("'%s'\n", str);
//	remove_spaces(str);
	printf("'%s'", remove_spaces(str));
}
char *remove_spaces(char *str) {
	int l = strlen(str);
	while (isspace(*str)) {
		str++;
	}
//	printf("'%s'\n",str);
	char *end;
	int len = strlen(str);
//	printf("l = %d len = %d\n", l,len);
	end = str + len - 1;
//	printf("%p  %p\n",str, end);
	while (end >= str && isspace (*end)) {
		end--;
	}
	*(end + 1) = '\0';
//	printf("'%s'\n", str);
	return str;
}
