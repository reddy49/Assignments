#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int main() {
	char ch[100][100] = {"sumanth","books","apple","mango","capgemini","platform","device","driver","panda","cricket","network"};
	char str1[15][15];
	char str[20];
	char s[20];
	int i,j;
	char c;
	int len;
	int ran,r;
	srand(time(0));
	for(int k = 0;k<1;k++) {
		ran = (rand() % (10 - 1 + 1)) + 1;
//		r   = (rand() % (
		printf("rsn = %d\n", ran);
	}
	for (i = 0;i < 10; i++) {
		strcpy(str1[i],ch[i]);
	}
	strcpy(s,str1[ran]);
	len = strlen(s);
	for( i = 0,j = 1;s[i] != '\0'||j<len;j = j+2,i = i + 2) {
		str[i] = s[i];
		str[j] = '_';
	}
	str[len] = '\0';
	i = 0;
	printf("Guess the word   %s\n", str);
	while(i < len) {
		if(str[i] == '_') {
			printf("Enter word in %s\n",str);
			scanf("%c", &c);
			if(s[i] == c && str[i] == '_') {
				str[i] = c;
				printf("str = %s\n", str);
			} else {
				continue;
				}
		}
		i++;
	}
}
