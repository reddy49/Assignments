#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
 
// Function Declaration
void create(char* name, int id, char gen, float sal, int len);
void display();
void insert(int pos, char* name, int id, char gen, float sal, int len);
void delete(int pos);
void reverse();
void count();
 
struct employee {
        char* name;
        int id;
        char gender;
        float salary;
        struct employee* link;
}*start; // Variable to store address of the starting node
 
int main()
{
	int choice, n, i, len;
    char* name;
    int id, pos;
    char gen;
    float sal;
    while(1) {
    	printf("\n_____Enter the choice_____\n1. Create\n2. Insert\n3. Delete\n4. Reverse\n5. Display\n6. Exit\n7. Count\n");
        scanf("%d", &choice); // Variable to store choice
        switch (choice)
        	{
            case 1:
            	start = NULL;
                printf("Enter the number of employee: ");
                scanf("%d", &n);
                __fpurge(stdin);
                for (i = 0; i < n; i++) {
                printf("\nEnter the length of name: ");
                scanf("%d", &len);
                __fpurge(stdin);
                name = (char*) malloc (len * sizeof(char));
                if (NULL == name) {
                     printf("Malloc failed for name\n");
                     exit(1);
                   }
                printf("Enter the name: ");
                if (NULL == fgets(name, len + 2, stdin)) {
                     printf("Fgets failed for name\n");
                  }
                *(name + strlen(name) - 1) = '\0';
                printf("Enter the id: ");
                scanf("%d", &id);
                __fpurge(stdin);
                printf("Enter the gender(F / M / O): ");
                scanf("%c", &gen);
                __fpurge(stdin);
               printf("Enter the Salary: ");
               scanf("%f", &sal);
               __fpurge(stdin);
               create(name, id, gen, sal, len);
               }
               printf("_____Successfully created linked list_____\n");
               break;
			case 2:
                        printf("Enter the position to insert: ");
                        scanf("%d", &pos);
                        __fpurge(stdin);
                        printf("\nEnter the length of name: ");
                        scanf("%d", &len);
                        __fpurge(stdin);
                        name = (char*) malloc (len * sizeof(char));
                        if (NULL == name) {
                                printf("Malloc failed for name\n");
                                exit(1);
                        }
                        printf("Enter the name: ");
                        if (NULL == fgets(name, len + 2, stdin)) {
                                printf("Fgets failed for name\n");
                        }
                        *(name + strlen(name) - 1) = '\0';
                        printf("Enter the id: ");
                        scanf("%d", &id);
                        __fpurge(stdin);
                        printf("Enter the gender(F / M / O): ");
                        scanf("%c", &gen);
                        __fpurge(stdin);
                        printf("Enter the Salary: ");
                        scanf("%f", &sal);
                        __fpurge(stdin);
                        insert(pos, name, id, gen, sal, len);
                        printf("______Successfully Inserted______\n");
                        break;
                case 3:
                        printf("Enter the position to delete: ");
                        scanf("%d", &pos);
                        __fpurge(stdin);
                        delete(pos);
                        printf("_____Successfully Deleted______\n");
                        break;
                case 4:
                        reverse();
                        printf("_____Successfully reversed the list_____\n");
                        break;
                case 5:
                        display();
                        break;
                case 6:
                        exit(1);
                case 7:
                        count();
                        break;
                default:
                        printf("Enter the valid input\n");
                }
        }
        free(start);
        free(name);
        start = NULL;
        name = NULL;
}

[9:37 AM] J Reddy, Pragathi
// Function to create a linked list
void create(char* name, int id, char gen, float sal, int len)
{
        struct employee *tmp = NULL;
        struct employee *q;
        tmp = (struct employee*) malloc (sizeof(struct employee));
        if (NULL == tmp) {
                printf("Malloc failed for tmp\n");
                exit(1);
        }
        tmp->name = (char*) malloc (len * sizeof(char));
        if (NULL == tmp->name) {
                printf("Malloc failed for tmp->link\n");
                exit(1);
        }
        strcpy(tmp->name, name);
        tmp->id = id;
        tmp->gender = gen;
        tmp->salary = sal;
        tmp->link = NULL;
        if (start == NULL) {
                start = tmp;
        } else {
                q = start;
                while (q->link != NULL) {
                        q = q->link;
                }
                q->link = tmp;
        }
        q = NULL;
}
 
void insert(int pos, char* name, int id, char gen, float sal, int len)
{
        int i = 1;
        struct employee *tmp = NULL;
        struct employee *q;
        tmp = (struct employee*) malloc (sizeof(struct employee));
        if (NULL == tmp) {
                printf("Malloc failed for temp\n");
                exit(1);
        }
        tmp->name = (char*) malloc (len * sizeof(char));
        if (NULL == tmp->name) {
                printf("Malloc failed for tmp->name\n");
                exit(1);
        }
        strcpy(tmp->name, name);
        tmp->id = id;
        tmp->gender = gen;
        tmp->salary = sal;
        if (start == NULL) {
                tmp->link = NULL;
                start = tmp;
        } else if (pos == 1) {
                tmp->link = start;
                start = tmp;
        } else {
                q = start;
                while (i != pos - 1) {
                        q = q->link;
                        i++;
                }
                tmp->link = q->link;
                q->link = tmp;
        }
        q = NULL;
}

[9:38 AM] J Reddy, Pragathi
void delete(int pos)
{
        int i = 1;
        struct employee *q;
        struct employee *tmp;
        if (pos == 1) {
                tmp = start;
                start = start->link;
                free(tmp);
        } else {
                q = start;
                while (i != pos - 1) {
                        q = q->link;
                        i++;
                }
                tmp = q->link;
                q->link = tmp->link;
                free(tmp);
        }
        q = NULL;
}
 
void reverse()
{
        struct employee *p1;
        struct employee *p2;
        struct employee *p3;
        if (start->link ==      NULL) {
                return;
        }
        p1 = start;
        p2 = p1->link;
        p3 = p2->link;
        p1->link = NULL;
        p2->link = p1;
        while (p3 != NULL) {
                p1 = p2;
                p2 = p3;
                p3 = p2->link;
                p2->link = p1;
        }
        start = p2;
        p1 = NULL;
        p2 = NULL;
        p3 = NULL;
}
 
void display()
{
        struct employee *q;
        int i = 1;
        if (start == NULL) {
                printf("List is empty\n");
                return;
        }
        q = start;
        while (q != NULL) {
                printf("\nEmployee %d:\nName : %s\n", i, q->name);
                printf("Id : %d\n", q->id);
                printf("Gender : %c\n", q->gender);
                printf("Salary : %f\n", q->salary);
                q = q->link;
                i++;
        }
        printf("\n");
        q = NULL;
}
 
void count()
{
        struct employee *q;
        int count = 0;
        if (start == NULL) {
                printf("List is empty\n");
                return;
        }
        q = start;
        while (q != NULL) {
                count++;
                q = q->link;
        }
        printf("\nNumber of employees are %d\n", count);
}


