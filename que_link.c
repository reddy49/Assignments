#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* rear = NULL;
struct node* front = NULL;
void qrear();
void deque();
void display();
int main()
{
    int ch;
    while(1) {
        printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:qrear();
            break;
            case 2:deque();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default:
            printf("enter correct choice");
        }
    }
}
void qrear() {
    int item;
    if(rear == NULL) {
    rear = (struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&rear->data);
    rear->next = NULL;
    front = rear;
    } else {
    rear->next = (struct node*)malloc(sizeof(struct node));
    rear = rear->next;
    printf("enter data");
    scanf("%d",&rear->data);
    rear->next = NULL;
    }
}
void deque() 
{
    struct node* temp;
    if(front == NULL) {
        printf("deletion not possible");
    } else {
        temp = front;
        front = front->next;
        temp->next = NULL;
       free(temp);
    }
}
void display() 
{
    struct node* temp;
    if(rear == NULL) {
        printf("queue is empty");
    }
    temp = front;
    while(temp != NULL) {
        printf("%d->",temp->data);
        temp = temp->next;
    }
}

