#include<stdio.h>
#include<stdlib.h>
int atoii(char *str);
int main()
{
	char *str;
	str = (char *) malloc (20 * sizeof(char));
	printf("Enter string");
	fgets(str,20,stdin);
	int i = atoii(str);
	printf("%d", i);
}

int atoii(char *str)
{
	int i = 0;
	int s = 1;
	char *ptr = str;
	if (*ptr == '-') {
		s = -1;
		ptr++;
	} else if(*ptr == '+') {
		ptr++;
	}
	while(*ptr) {
		if((*ptr >= '1' && *ptr <= '9')) {
			i = i * 10 + (*ptr - '0');
		}
		ptr++;
	}
	return i * s;
}
