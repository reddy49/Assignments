#include <stdio.h>
#include<stdlib.h>
struct Node {
    int data;
//      int num;
    struct Node* next;
}*q,*head,*newnode;

int create();
int insert();
int display();
int main()
{
      create();
      insert();
      display();
}
int create()
{
//      struct Node *newnode;
    newnode = (struct Node*) malloc (sizeof(struct Node));
        printf("enter the node data");
    scanf("%d",&newnode->data);
        newnode->next = NULL;
        head = newnode;
    printf("%d->\n", newnode->data);
 //   head->next = NULL;
}
int insert()
{
        int i = 1;
        while (i) {
        //create(data);
        struct Node *temp;
        temp = (struct Node*) malloc (sizeof(struct Node));
        printf("Enter data");
        scanf("%d", &temp->data);
//              temp->head = head;
                newnode->next = temp;
                temp->next = NULL;
                newnode = newnode->next;
                printf("1 - continue, 0 - end\n");
                scanf("%d", &i);
                if (i == 0) {
                        break;
                } else {
                        continue;
                }
        }
}
int display()
{
        struct Node *temp = head;
        while (temp != NULL) {
                printf("%d->",temp->data);
                temp = temp->next;
                }
//      return 0;
}
