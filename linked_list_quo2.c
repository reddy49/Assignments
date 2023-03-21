#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
	int id;
	char name[20];
	char gender[10];
	char occupation[20];
	int age;
	struct Node *next;
	struct Node *prev;
};

struct Node *create();
void display(struct Node *);

int main()
{
	struct Node *head = NULL;
	head = create();
//	create();
	display(head);	
}

struct Node *create()
{
	struct Node *head1 = NULL;
	struct Node *new;
	struct Node *temp;
	FILE *fp;
	fp = fopen("ClubMembership.txt", "r");
	int ch;
	while (ch != EOF) {
		new = (struct Node*) malloc (sizeof(struct Node));
		ch = fscanf(fp,"%d%s%s%s%d", &new->id, new->name, new->gender, new->occupation, &new->age);
		new->next = NULL;
		new->prev = NULL;
		if (head1 == NULL) {
		//	printf("List is empty");
			head1 = new;
			temp = new;
		} else {
			temp->next = new;
			new->prev = temp;
			temp = temp->next;
		//	while(temp->next != NULL) {
		//		temp = temp->next;
			}
	//	temp->next = new;
	}
	return head1;
}
void display(struct Node *head)
{
//	struct Node *head;
	struct Node *temp = head;
	while (temp->next != NULL) {
		printf("%d\t", temp->id);
		printf("%-10s\t", temp->name);
		printf("%-10s\t", temp->gender);
		printf("%-10s\t", temp->occupation);
		printf("%d\n", temp->age);
		temp = temp->next;
	}
//	printf("\n");
}
