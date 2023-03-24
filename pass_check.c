#include<stdio.h>
#include<string.h>
#include<ctype.h>
int pass_ch(char pass[], char spcl_ch[]);
int main ()
{
	char spcl_ch[20] = "!@#$%^&*~?";
	char pass[20];
	printf("Enter password:");
	scanf("%s", pass);
	pass_ch(pass,spcl_ch);
}

int pass_ch(char pass[], char spcl_ch[]) {
	int len = strlen(pass);
	int flag = 1;
	int i = 0,j=0;
	int c=0,c1=0,c2=0,c3=0,c4;
	if(len < 8) {
		printf("Password is too short\n");
	}
	if (len > 7) {
		while (pass[i] != '\0') {
			j = 0;
			while (spcl_ch[j] != '\0') {
				if (pass[i] == spcl_ch[j]) {
					c = 1;
					break;
				}
				j++;
			}
			if(isdigit(pass[i])) {
				c1 = 1;
			}
			if(pass[i] >= 'A' && pass[i] <= 'Z') {
				c2 = 1;
			} 
			if(pass[i] >= 'a' && pass[i] <= 'z') {
				c3 = 1;
			}
		i++;
		}
	}
	if (c & c1 & c2 & c3) {
		printf("strong\n");
	} else {
		printf("not strong\n");
	}
	if(!c) {
		printf("Need special character\n");
	}
	if(!c1) {
		printf("Need atleast one numeric\n");
	}
	if(!c2) {
		printf("Need one uppercase\n");
	}
	if(!c3) {
		printf("Need one alphabet\n");
	}
}
