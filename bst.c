# include <stdio.h>
# include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;

node* newnode(int key) {
	node* temp = (node*)malloc(sizeof(node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node* insert(node* root, int key) {
	if (root == NULL) {
		return newnode(key);
	}
	else {
		if (key < root->data) {
			root->left = insert(root->left, key);
		}
		else {
			root->right = insert(root->right, key);
		}
	}
	return root;
}

node* search(node* root, int key) {
	if (root == NULL || root->data == key) {
		return root;
	}
	if (key < root->data) {
		return search(root->left, key);
	}
	else {
		return search(root->right, key);
	}
}

void inorder(node* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root) {
	if (root != NULL) {
		postorder(root->right);
		postorder(root->left);
		printf("%d ", root->data);
	}
}


void main() {
	node* root = NULL;
	node* temp = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	temp = search(root, 70);
	if (temp != NULL) {
		printf("Found");
	}
	else {
		printf("Not found");
	}
}
