#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "time.h"

typedef struct node {
	int data;
	struct node *pNext;
}Node;

Node *createNode(int newData);
int detectLoop(Node **listThing);
void reverseList(Node **listThing);

int main(void) {

}

Node *createNode(int newData) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->pNext = NULL;
	return newNode;
}

int detectLoop(Node **listThing) {
	Node *iterator = *listThing;
	Node *track[100];
	int index = 0;
	track[0] = iterator;
	iterator = iterator->pNext;
	while (iterator != NULL) {
		track[index] = iterator;
		for (int c = 0; c < 100; ++c) {
			if (track[c] == iterator) {
				return 1;
			}
		}
		++index;
		iterator = iterator->pNext;
	}
	return 0;
}

void reverseList(Node **listThing) {

}

void insertAtFront(Node **listThing, int newData) {
	Node *newNode = createNode(newData);
	*listThing = newData;
	*
}