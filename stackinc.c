#include<stdio.h>
#include<stdlib.h>

#define n 4
int push();
int pop();
int show();
int top = 0;
int arr_size[n];
int main()
{
//	int arr[10];
	int choice;
//	printf("Enter the size of stack");
//	scanf("%d", arr_size);
	while (1) {
		printf("\nOpeartions performed by stack:");
		printf("\n1.push\n2.pop\n3.show\n4.exit");
		printf("\nEnter the choice");
		scanf("%d", &choice);
		switch (choice) {
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: show();
				break;
			case 4: exit(0);
			printf("\nInvalid choice");
		}
	}
}

int push()
{
	int x;
	if (top == n) {
		printf("\nStack is full");
	} else {
		printf("\nEnter element into a stack");
 		scanf("%d", &x);
		top = top + 1;
		arr_size[top] = x;
	}
}
int pop()
{
	
	if (top == 0) {
		printf("\nStack is empty");
	} else {
		printf("\nPopped element is %d", arr_size[top]);
		top = top - 1;
		}
}
int show()
{
	if (top == 0) {
		printf("\nNo elements:");
	} else {
		 printf("\nElements in stack is:");
		for (int i = top; i >= 0; i--) {
			printf("%d\n", arr_size[i]);
		}
	}
}
		





