#include<stdlib.h>
#include <stdio.h>
struct node{
    int data;
    struct node* next;
}*head1 = NULL,*head2=NULL,*head3 = NULL;
struct node *create(struct node* head,int data);
struct node* add(struct node* head1,struct node* head2,int data);
int display();
int main()
{
    int num;
    int data;
	printf("Enter no of nodes in list1");
    scanf("%d", &num);
    for(int i = 0;i <num;i++) {
       printf("enter list 1 data");
       scanf("%d",&data);
       head1 = create(head1,data);
   }
   printf("Enter no of nodes in list2");
   scanf("%d", &num);
   for(int i = 0;i <num;i++) {
       printf("enter list 2 data");
       scanf("%d",&data);
       head2 = create(head2,data);
   }
   printf("\nLinked list 1\n");
   display(head1);
    printf("\nLinked list 2\n");
   display(head2);
   head3 = add(head1,head2,data);
    printf("\nLinked list 3\n");
    display(head3);
}
struct node *create(struct node* head,int data)
{
    //int data;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if(head == NULL) {
        head = temp;
    } else
    {
        struct node* q;
        q = head;
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = temp;
        temp->next = NULL;
    }
    return head;
}
struct node* add(struct node* head1,struct node* head2,int data)
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *curr = head;
    int carry = 0;
    while(head1 != NULL || head2 != NULL) {
        if(head1) {
            curr->data= curr->data + head1->data;
            head1 = head1->next;
        }
        if(head2) {
            curr->data=curr->data + head2->data;
            head2 = head2->next;
        }
        if(carry) {
            curr->data = curr->data + carry;
            carry = 0;
        }
        if(curr->data > 9 && head1 != NULL && head2 != NULL) {
            carry = curr->data/10;
            curr->data = curr->data %10;
        }
        if(head1 || head2 || carry) {
            curr->next = (struct node*)malloc(sizeof(struct node));
            curr = curr->next;
        }
    }
    return head;
}
int display(struct node *head)
{
    struct node *temp;
    temp = head;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

