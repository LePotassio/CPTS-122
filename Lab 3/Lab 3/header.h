#ifndef HEADER_H
#define HEADER_H
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "time.h"
#include "string.h"


//Typedefs
typedef struct node {
	double value;
	struct node *pNext;
} Node;

//

int isEmpty(Node *jenga);
void push(Node **domino, double value);
void pop(Node **d6);
double peek(Node *waffle);

#endif