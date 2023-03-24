#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int r;
	srand(time(0));
	for (int i = 0;i<1;i++) {
		r = (rand() % (3 - 1 + 1)) + 1;
	}
	if(r == 1) {
		printf("* * * *\n"
			   "*     *\n"
			   "* * * *\n"
			   "**     \n"
			   "* *    \n"
			   "*   * *\n");
//		printf("\n");
	} else if(r == 2) {
		printf("* * * *\n"
			   "*     *\n"
			   "* * * *\n"
			   "*      \n"
			   "*      \n"
			   "*      \n");
	} else {
		printf("* * * *\n"
			   "*      \n"
			   "* * * *\n"
			   "      *\n"
			   "      *\n"
			   "* * * *\n");
	}
	
}
