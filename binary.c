#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
//struct Node* root;
struct Node* create();
void inorder(struct Node*);
int main()
{
//	int data;
	struct Node* root;
	root = NULL;
	root = create();
//	create();
	printf("In order");
	inorder(root);
	printf("\n");
}

struct Node* create()
{
	struct Node *newnode;
	//int data;
	int x;
	newnode = (struct Node*) malloc (sizeof(struct Node));
	printf("Enter data(-1 for no nodes)");
	scanf("%d", &x);
	if(x == -1) {
		return 0;
	}	
//	printf("enter nodes or -1 to discontinue");
//	scanf("%d", &x);
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	printf("Enter left node%d\n", x);
	newnode->left = create();
	printf("Enter right node%d\n", x);
	newnode->right = create();
//	printf("%d->", data);
	return newnode;
}
/*void search()
{
	int key;
	int flag;
	printf("Enter key");
	scanf("%d", &key);
	if (data == root->data) {
		flag = 1;
	}
	if (flag == 1) {
		printf("Succesful");
	} else {
		printf("Unsuccesful");
	}
}*/
void inorder(struct Node* root)
{
	if(root != NULL) {
		inorder(root->left);
		printf("%d->", root->data);
		inorder(root->right);
	}
}
