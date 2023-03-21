#include <stdio.h>
#include<stdlib.h>
struct Node {
    int data;
//	int num;
    struct Node* next;
}*q,*head,*newnode;

int create();
int insert();
int display();
int insertpos();
int delete();
int search();
int main()
{
//	create();
//	insert();
//	display();
//	insertpos();
//	display();
	int ch;
	while(1) {
		printf("\n1.create()\n2.insert\n3.insertpos\n4.delete\n5.display\n6.search\n7.exit\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				create();
			break;
			case 2:
				insert();
			break;
			case 3:
				insertpos();
			break;
			case 4:
				delete();
				break;
			case 5:
				display();
			break;
			case 6:
				search();
			break;
			case 7:
				//struct Node *temp = head;
				while(head != NULL) {
					free(head);
					head = head->next;
				}
				exit(1);
			break;
			default:
				printf("Enter a correct choice");
				break;
		}
	}
}
int create()
{
//	struct Node *newnode;
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
//		temp->head = head;
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
	
	
//	return newnode;
	}
}

int insertpos()
{
	int pos;
//	int *q;
	int i = 1;
	struct Node *temp1;
	temp1 = (struct Node*) malloc (sizeof(struct Node));
	printf("Enter the data");
	scanf("%d", &temp1->data);
	printf("Enter the position");
	scanf("%d", &pos);
	q = head;
//	temp1 = head;
	while (i != pos - 1) {
		q = q->next;
		i++;
	}
	temp1->next = q->next;
	q->next = temp1;
} 
int delete()
{
	int pos;
	int i = 1;
	struct Node *temp;
	printf("Enter location");
	scanf("%d", &pos);
	q = head;
	while (i != pos - 1) {
		//
		q = q->next;
//		q = temp->next;
//		head = head->next;
		i++;
	}
//	temp->next = q->next;
	temp = q->next;
	q->next = temp->next;
	free(temp);
}

int search()
{
	int val;
	int flag = 0;
	struct Node *temp;
	printf("Enter element you wanr to search\n");
	scanf("%d", &val);
	temp = head;
	while (temp != NULL) {
		if(temp->data == val) {
			flag =1;
			break;
		}
		temp = temp->next;
	}
	if (flag == 1) {
		printf("Element is found");
	} else {
		printf("element is not found");
		}
}

		
int display()
{
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d->",temp->data);
		temp = temp->next;
		}
//	return 0;
}
