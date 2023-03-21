
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
};

struct Node *create();
void display(struct Node *);
struct Node *sort(struct Node* head);

int main()
{
        struct Node *head = NULL;
        head = create();
//      create();
        display(head);
        sort(head);
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
//			if(strcmp(new->gender,"Male") < 0) {
                new = (struct Node*) malloc (sizeof(struct Node));
                ch = fscanf(fp,"%d%s%s%s%d", &new->id, new->name, new->gender, new->occupation, &new->age);
                new->next = NULL;
                if (head1 == NULL) {
                //      printf("List is empty");
                        head1 = new;
                        temp = new;
                } else {
                        temp->next = new;
                        temp = temp->next;
                //      while(temp->next != NULL) {
                //              temp = temp->next;
                        }
        //      temp->next = new;
    	//}
	}
        return head1;
}

struct Node *sort(struct Node* head) {
    struct Node *i=NULL,*j=NULL,*temp=NULL;
    temp = (struct Node*) malloc (sizeof(struct Node));
    for(i = head;i->next != NULL;i = i->next) {
        for (j = i->next;j->next != NULL;j = j->next) {
            if(strcmp(j->gender,"Male") == 0) {
                temp->id = j->id;
                strcpy(temp->name, j->name);
                strcpy(temp->gender,j->gender);
                strcpy(temp->occupation,j->occupation);
                temp->age = j->age;
                
                j->id = i->id;
                strcpy(j->name, i->name);
                strcpy(j->gender,i->gender);
                strcpy(j->occupation,i->occupation);
                j->age = i->age;
                
                i->id = temp->id;
                strcpy(i->name, temp->name);
                strcpy(i->gender,temp->gender);
                strcpy(i->occupation,temp->occupation);
                i->age = temp->age;
            }
        }
    }
    free(temp);
    return head;
}
void display(struct Node *head)
{
        struct Node *temp = head;
		struct Node *temp1;
		strcpy(temp1->gender,"Male");
        while (temp->next != NULL) {
//			if(strcmp(temp->next->gender,temp1->gender) == 0) {
                printf("%d\t", temp->id);
                printf("%-10s\t", temp->name);
                printf("%-10s\t", temp->gender);
                printf("%-10s\t", temp->occupation);
                printf("%d\n", temp->age);
                temp = temp->next;
			}
/*			}else {
				printf("%d\t", temp->id);
                printf("%-10s\t", temp->name);
                printf("%-10s\t", temp->gender);
                printf("%-10s\t", temp->occupation);
                printf("%d\n", temp->age);
                temp = temp->next;
			}*/
        }
//      printf("\n");

