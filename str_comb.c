#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char str[5] = "abcd";
	char ch[5] = "cd";
	int i,j=0,k=0;
	int len = strlen(str);
	int l = len - 1;
	char temp;
	for(int m = 0;m < 4;m++) {	
		l = len - 1;
		for(i = 0;i < len -1;i++) {
			temp = str[l];
			str[l] = str[l -1];
			str[l - 1] = temp;
			printf("%s  ",str);
			l--;
		}
	}
}
