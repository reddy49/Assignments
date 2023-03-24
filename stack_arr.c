#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 10
// struct stack {
//     int data;
//     struct stack *next;
// }*top
int push1();
int push2();
int pop1();
int pop2();
int display();
int display1();
int arr[10];
int top = -1;
int top1 = SIZE;
int data,data1;
int main() {
    int ch;
    while(1) {
    printf("Enter choice\n");
    printf("1.push1\n2.push2\n3.pop1\n4.pop2\n5.display\n6.display2\n7.exit\n");
    scanf("%d",&ch);
        switch(ch) {
            case 1:push1();
            break;
            case 2:push2();
            break;
            case 3:pop1();
            break;
            case 4:pop2();
            break;
            case 5: display();
            break;
            case 6:display1();
            break;
            case 7:
            exit(0);
            default:
            printf("enter corect choice");
        }
    }
}
int push1(){
    if(top == top1 || top == SIZE) {
        printf("stack1 is full");
    } else
        printf("Enter data\n");
            scanf("%d",&data);
        top = top + 1;
        arr[top] = data;
}
int push2(){
    if(top == top1 || top1 == -1) {
        printf("stack2 is full");
    } else
     printf("Enter data\n");
            scanf("%d",&data);
        top1 = top1 - 1;
        arr[top1] = data;
}
int pop1() 
{
	if (top == -1) {
		printf("Satck is empty");
	} else {
		top = top - 1;
	}
}
int pop2()
{
	if (top1 == SIZE) {
		printf("Stack is empty");
	} else {
		top1 = top1 + 1;
	}
}
int display() {
    if (top == SIZE - 1) {
        printf("no data");
    } else {
        for(int i = top;i>=0;i--) {
            printf("%d ", arr[i]);
        }
    }
}
int display1() {
    if (top == SIZE- 1) {
        printf("no data");
    } else {
        for(int i = top1;i<SIZE;i++) {
            printf("%d ", arr[i]);
        }
    }
}

