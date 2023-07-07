#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int data) {
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
	struct Node* newNode = createNode(data);
	if (root == NULL)
		return newNode;
	struct Node* temp = root;
	while (temp != NULL) {
		if (data > temp->data) {
			if (temp->right == NULL) {
				temp->right = newNode;
				return root;
			}
			temp = temp->right;
		} else {
			if (temp->left == NULL) {
				temp->left = newNode;
				return root;
			}
			temp = temp->left;
		}
	}
	return root;
}

int search(struct Node* root, int value) {
	if (root == NULL) {
		printf("Arbre vide");
		return 0;
	}
	struct Node* temp = root;
	while (temp != NULL) {
		if (value == temp->data) {
			return 1;
		} else if (value > temp->data) {
			temp = temp->right;
		} else {
			temp = temp->left;
		}
	}
	return 0;
}

struct Node* searchRecursive(struct Node* root, int value) {
	if (root == NULL) {
		return NULL;
	}
	if (value == root->data) {
		return root;
	} else if (value < root->data) {
		return searchRecursive(root->left, value);
	} else {
		return searchRecursive(root->right, value);
	}
}

// Pre-order traversal (Root-Left-Right)
void preOrder(struct Node* root) {
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

// In-order traversal (Left-Root-Right)
void inOrder(struct Node* root) {
	if (root == NULL)
		return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

// Post-order traversal (Left-Right-Root)
void postOrder(struct Node* root) {
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}

int main() {
	struct Node* root = NULL;
	root = insertNode(root, 50);
	root = insertNode(root, 30);
	root = insertNode(root, 20);
	root = insertNode(root, 40);
	root = insertNode(root, 70);
	root = insertNode(root, 60);
	root = insertNode(root, 80);

	printf("Pre-order traversal: ");
	preOrder(root);
	printf("\n");

	printf("In-order traversal: ");
	inOrder(root);
	printf("\n");

	printf("Post-order traversal: ");
	postOrder(root);
	printf("\n");

	return 0;
}
