#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*temp;
struct node* top=0;
int push(int data);
int pop();
int display();
int push(int data)
{
    temp = (struct node*)malloc(sizeof(struct node));
	if (top == 0) {
		top = temp;
		temp -> data = data;
        temp->next = 0;
    } else {
		temp -> data = data;
        temp->next = top;
        top = temp;
		}
}
int pop() 
{
    if(top == 0) {
        printf("list is empty");
    } else {
        temp = top;
        top = temp->next;
        temp->next = 0;
        free(temp);
    }
}
int display()
{
    temp = top;
    if(top == 0) {
        printf("list is empty");
    } else {
        while(temp != 0) {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
	int data;
   int ch;
   while(1) {
       printf("\n1.push\n2.pop\n3.display\n4.exit\n");
       scanf("%d", &ch);
       switch(ch) {
           case 1:
			printf("Enter data");
			scanf("%d", &data);
			push(data);
           break;
           case 2:pop();
           break;
           case 3:display();
           break;
           case 4:exit(0);
           default:
           printf("Enter correct choice");
       }
   }
}

