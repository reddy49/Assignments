#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>



struct node{
        char *name;
        char gender : 3;
        int id;
        float salary;
        struct node *next;
        };



int main()
{
	struct node  e1,*temp, *head, *newnode;
	char str[100];
    int len;
   	int choice;
    head = NULL;
    while (choice) {
     //      __fpurge(stdin);
    	newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter length of name:");
        scanf("%d",&len);
        newnode->name = (char*) malloc (sizeof(len));
        printf("\nEnter the name:");
        scanf("%s",newnode->name);
        __fpurge(stdin);
       //e1.name = str;
       //newnode -> name = str;
        printf("Enter the id to insert: ");
        scanf("%d", &newnode -> id);
        newnode -> next = NULL;
        if (head == NULL) {
			head = newnode;
            temp = newnode;
         } else {
        	     temp -> next = newnode;
                 temp = newnode;
                 }
        printf("Enter the choice 1.continue 0.stop\n");
        scanf("%d", &choice);
        }

        temp = head;
        while (temp != NULL) {
	        printf("\nEmployee name and ID is :");
            printf("%s\t",temp->name);
            printf("%d",temp -> id);
            temp = temp -> next;
            //printf("\n");
            }
free(head);
free(newnode);
free(temp);
head = NULL;
newnode = NULL;
temp = NULL;
return 0;
}
