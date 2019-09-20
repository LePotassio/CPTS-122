#include "header.h"


//Function Defs

int isEmpty(Node *jenga) {
	if (jenga == NULL) {
		return 1;
	}
	return 0;
}

void push(Node **domino, double value) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->pNext = NULL;
	newNode->value = value;
	newNode->pNext = *domino;
	*domino = newNode;
}

void pop(Node **d6) {
	if (isEmpty(*d6)) {
		return;
	}
	Node *temp = *d6;
	*d6 = (*d6)->pNext;
	free(temp);
}

double peek(Node *waffle) {
	return waffle->value;
}