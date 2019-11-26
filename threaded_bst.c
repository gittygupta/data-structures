# include <stdio.h>
# include <stdlib.h>

typedef struct node {
	int data, isThreaded;
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

node* leftmost(node* root) {
	while (root != NULL && root->left != NULL) {
		root = root->left;
	}
	return root;
}

void inorder(node* root) {
	if (root == NULL) {
		return;
	}
	node* current = leftmost(root);
	while (current != NULL) {
		printf("%d ", current->data);
		if (current->isThreaded) {
			current = current->right;
		}
		else {
			current = leftmost(current->right);
		}
	}
}

void inOrder(node* root) {
	if (root != NULL) {
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}

node* createThreaded(node* root) {
	if (root == NULL) {
		return NULL;
	}
	if (root->left == NULL && root->right == NULL) {
		return root;
	}
	if (root->left != NULL) {
		node* l = createThreaded(root->left);
		l->right = root;
		l->isThreaded = 1;
	}
	if (root->right == NULL) {
		return root;
	}
	return createThreaded(root->right);
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
	inOrder(root);
	printf("\n");
	temp = search(root, 70);
	if (temp != NULL) {
		printf("Found");
	}
	else {
		printf("Not found");
	}
}