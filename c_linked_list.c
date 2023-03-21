#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
}*head, *newnode, *temp;
int create();
int addelements();
int insertpos();
int display();
int insertbeg();
int delete();
int insertatend();
int main()
{
	int ch;
	while (1) {
		printf("\n1.create\n2.addelements\n3.insertpos\n4.display\n5.exit\n6.insertbeg\n7.delete\n8.insertatend\n");
		scanf("%d", &ch);
		switch (ch) {
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
				insertbeg();
			break;
			case 7:
				delete();
			break;
			case 8:
				insertatend();
				break;
			default:
				printf("enter correct choice");
			break;
		}
	}
}
int create()
{
//	head = NULL;
	temp = head;
	newnode = (struct Node*) malloc (sizeof(struct Node));
	printf("Enter element");
	scanf("%d", &newnode->data);
	newnode->next = newnode;
	head = newnode;
	printf("%d->", newnode->data);	
}
int addelements()
{
	struct Node *q;
	temp = head;
//	temp1 = head;
	int i = 1;
	while (i) {
		newnode = (struct Node*) malloc (sizeof(struct Node));
		printf("Enter data\n");
		scanf("%d", &newnode->data);
		if(head == NULL) {
			printf("list is empty");
		} else {
			q = head;
			while (q->next != temp) {
				q = q->next;
			}
			newnode->next = head;
			q->next = newnode;		
		}
		printf("1- continue, 0-exit");
		scanf("%d", &i);
		if (i == 0) {
			break;
		} else {
			continue;
			}
	}
}
int insertbeg()
{
	newnode = (struct Node*) malloc (sizeof(struct Node));
	struct Node *q;
//	temp = head;
	printf("Enter new data");
	scanf("%d", &newnode->data);
	if (head == NULL) {
		printf("List is empty");
	} else {
		newnode->next = head;
		q = head;
		while (q->next != head) {
			q = q->next;
		}
		q->next = newnode;
		head = newnode;
	}
}
int insertpos()
{
	int pos;
	newnode = (struct Node*) malloc (sizeof(struct Node));
	struct Node *q;
	temp = head;
	printf("Enter new data");
	scanf("%d", &newnode->data);
	printf("Enter pos");
	scanf("%d", &pos);
	if (head == NULL) {
		printf("List is empty");
	} /*else if(pos == 1) {
		newnode->next = head;
		q = head;
		while (q->next != head) {
			q = q->next;
		}
		q->next = newnode;
		head = newnode;*/
	 else {
		q = head;
		int i = 1;
		while (i != pos - 1) {
			q = q->next;
			i++;
		}
		newnode->next = q->next;
		q->next = newnode;
		}
}
int insertatend()
{
	newnode = (struct Node *) malloc(sizeof(struct Node));
	printf("Enter data\n");
	scanf("%d", &newnode->data);
	temp = head;
	while(temp->next != head) {
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->next = head;
}
int delete()
{
	int pos;
	int i = 1;
	struct Node *q;
	printf("Enter location");
	scanf("%d", &pos);
	if (head == NULL) {
		printf("deletion not possible");
	} else {
		q = head;
		while (i != (pos - 1)) {
			q = q->next;
			i++;
		}
		temp = q->next;
		q->next = temp->next;
		free(temp);
	}
}
int display()
{
	
	if(head == NULL) {
		printf("List is empty");
	} else {
		temp = head;
	//	printf("Linked list");
		while (temp->next != head) {
			printf("%d->", temp->data);
			temp = temp -> next;
		}
		printf("%d", temp->data);
//	printf("NULL");
	}
}
