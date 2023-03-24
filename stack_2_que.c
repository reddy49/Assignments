#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int q1[SIZE];
int q2[SIZE];
int r1 = -1;
int r2 = -1;
int f1 = -1;
int f2 = -1;
int data;
void push();
void pop();
void display();
int main()
{
	int ch;
	while (1) {
		printf("Enter choice\n");
		printf("1.push\n2.pop\n3.display\n4.exit\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4:
					exit(0);
					break;
			default:
				printf("Enter correct choice");
		}
	}
}
void push()
{
	if (r1 == SIZE-1) {
		printf("stack is full");
	} else {
		f1 = 0;
		printf("Enter data");
		scanf("%d", &data);
		r1 = r1 + 1;
		q1[r1] = data;
	}
}
void pop()
{
	if (f1 == -1 && r1 == -1) {
		printf("stack is empty");
	} else {
		while (f1 != r1) {
			f2 = 0;
			r2++;
			q2[r2] = q1[f1];
			f1++;
		}
		q1[SIZE] = '\0';
		r1 = -1;
		f1 = -1;
		while (f2 <= r2) {
			f1 = 0;
			r1++;
			q1[r1] = q2[f2];
			f2++;
		}
		q2[SIZE] = '\0';
		f2 = -1;
		r2 = -1;
	}
}
void display()
{
	int i;
	for (i = r1; i >= f1; i--) {
		printf("%d \n", q1[i]);
	}
}
