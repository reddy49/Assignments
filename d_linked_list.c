#include<stdio.h>
#include<stdlib.h>

struct Node {
	//int data;
	struct Node *prev;
	int data;
	struct Node *next;
	};
struct Node *head;
struct Node *newnode;
int create();
int addelements();
int insertpos();
int display();
//int insbeg();
int deletepos();
int main()
{
//create();	
//insert();
//display();
	int ch;
	while(1) {
		printf("\n1.create\n2.addelements\n3.insertpos\n4.display\n5.extit\n6.insbeg\n7.delete\n");
		scanf("%d", &ch);
		switch(ch) { 
			case 1:
				create();
			break;
			case 2:
				addelements();
			break;
			case 3:
				insertpos();
			break;
			case 4:
				display();
			break;
			case 5:
				exit(1);
			break;
			case 6:
//				insbeg();
			break;
			case 7:
				deletepos();
			break;
			default:
				printf("Enter correct choice");
			break;
		}
	}
}
int create()
{
//	int data;
//	struct Node *newnode;
	newnode = (struct Node*) malloc (sizeof(struct Node));
	printf("Enter first node data\n");
	scanf("%d", &newnode->data);
	head = newnode;
	if (head == NULL) {
		printf("List is empty");
//		return NULL;
	} else {
		newnode->prev = NULL;
//		newnode->data = data;
		newnode->next = NULL;
		}
	printf("%d->", newnode->data);
}
int addelements()
{
	int i = 1;
	while (i) {
	struct Node *temp;
	temp = (struct Node*) malloc (sizeof(struct	Node));
	printf("\nEnter data\n");
	scanf("%d", &temp->data);
//	head = newnode;
	if (head == NULL) {
		printf("List is empty\n");
	} else {
		while (newnode->next != NULL) {
			newnode = newnode->next;
		}
		newnode->next = temp;
		temp->prev = newnode;
		temp->next = NULL;
	}
	printf("1-continue, 0-exit\n");
	scanf("%d", &i);
	if(i == 0) {
		break;
	} else {
		continue;
		}
	}
}

int insertpos()
{
	int pos;
	int i = 1;
	struct Node* temp;
	temp = (struct Node*) malloc (sizeof(struct Node));
	printf("Enter new data");
	scanf("%d", &temp->data);
	printf("Enter the pos");
	scanf("%d", &pos);
	newnode = head;
	if (head == NULL) {
		printf("List is empty");
	} else {
		while (i != pos - 1) {
			newnode = newnode->next;
			i++;
		}
		temp->next = newnode->next;
		newnode->next->prev = temp;
		temp->prev = newnode;
		newnode->next = temp;
		}
}
/*int insbeg()
{
	struct Node* temp;
	temp = (struct Node*) malloc (sizeof(struct Node));
	printf("Enter new data");
	scanf("%d", &temp->data);
//	newnode = head;
//	newnode->next=head;
	temp->prev = NULL;
	head->prev = temp;
	head=temp;
}*/
int deletepos()
{
	int pos;
	struct Node* temp;
	printf("Enter location");
	scanf("%d", &pos);
	newnode = head;
	int i = 1;
	if(head == NULL) {
		printf("Deletion is not possible");
		}	 
	else if(pos == 1) {
		newnode->next->prev = NULL;
		head = newnode->next;
		free(newnode);
		}
//	}
	 else {
		while (i != pos - 1) {
			newnode = newnode->next;
			i++;
		}
		temp = newnode->next;
		newnode->next = temp->next;
		temp->next->prev = newnode;
		free(temp);
	}
}
int display()
{
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
}
		

