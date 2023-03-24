#include<stdio.h>

int top1 = -1; //taking top1 for stack1
int top2 = -1; //taking top2 for stack2
int top3 = -1; //taking top3 for stack3

int sta1 [10]; //src stack or rod1
int sta2 [10]; //temp stack or rod2
int sta3 [10]; //dest tack or rod3

//function declaration for Tower of Honoi
int TOH(int n,char a,char b,char c); 

//Main function
int main()
{
	int i;
	int j;
	int k;
	int n;
	printf ("Enter disc number");
	scanf ("%d", &n);  // Taling n no of discs
	char a = 'a';
	char b = 'b';
	char c = 'c';
	for (i = n; i > 0; i--) { //taking discs in rod1
		top1++;
		sta1[top1] = i;
	}
	for(i = top1; i >= 0; i--) { 
		printf("%d ", sta1[i]);
	}
	printf("\n");  //printing 3 rods and discs
	for(i = top1,j = top3, k = top2; i >= 0 || j >= 0||k >= 0; i--, j--, k--) {
		printf("|%d |%d |%d|\n", sta1[i],sta3[j],sta2[k]);
	}
	printf("\n");
	TOH(n, 'a', 'b', 'c');  //calling functiom
}


