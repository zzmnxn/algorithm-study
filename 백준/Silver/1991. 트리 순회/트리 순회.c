#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct Node* right;
	struct Node* left;
}Node;

Node* MakeNode(char data) {
	if (data == '.') return NULL;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void Preorder(Node* root) {
	if (root == NULL) return;
	printf("%c", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node* root) {
	if (root == NULL) return;
	Inorder(root->left);
	printf("%c", root->data);
	Inorder(root->right);
}

void Postorder(Node* root) {
	if (root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%c", root->data);
}

void FreeTree(Node* root) {
	if (root == NULL) return;
	FreeTree(root->left);
	FreeTree(root->right);
	free(root);
}
int main() {
	Node* nodes[26] = { 0 };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char parent, left, right;
		scanf(" %c %c %c", &parent, &left, &right);

		if (nodes[parent - 'A'] == NULL) {
			nodes[parent - 'A'] = MakeNode(parent);
		}
		Node* parentNode = nodes[parent - 'A'];

		if (left != '.') {
			nodes[left - 'A'] = MakeNode(left);
			parentNode->left = nodes[left - 'A'];
		}

		if (right != '.') {
			nodes[right - 'A'] = MakeNode(right);
			parentNode->right = nodes[right - 'A'];
		}
	}
	Node* root = nodes[0];
	Preorder(root);
	printf("\n");
	Inorder(root);
	printf("\n");
	Postorder(root);
	FreeTree(root);
	return 0;
}