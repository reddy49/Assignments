#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include<stdlib.h>
int insert(char *ch, int pos, char c);
int main()
{
	char *ch;
	char c;
	int pos;
	ch = (char *) malloc (30 *sizeof(char));
	printf("enter a string");
	fgets(ch,30,stdin);
	printf("enter char");
	scanf("%c", &c);
	__fpurge(stdin);
	printf("Enter pos");
	scanf("%d", &pos);
	__fpurge(stdin);
	insert(ch,pos,c);
	printf("%s", ch);

}
int insert(char *ch, int pos ,char c) {
	int len = strlen(ch);
	int i = len - 1;
	while (*(ch + i)) {
		*(ch + len) = *(ch + len - 1);
		if (pos == i) {
			*(ch + i) = c;
			break;
		}
		i--;
		len--;
	}
}
