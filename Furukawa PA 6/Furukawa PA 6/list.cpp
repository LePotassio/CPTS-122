#include "list.h"

list::list() {
	pHead = nullptr;
}
list::~list() {
	deleteRecursive(pHead);
}

node *list::getPHead() {
	return pHead;
}
void list::setPHead(node *newPHead) {
	pHead = newPHead;
}

void list::insertFront(std::string recordN, int idNum, std::string name, std::string email, std::string unit, std::string program, std::string level) {
	if (pHead == nullptr) {
		node *newNode = new node(recordN, idNum, name, email, unit, program, level);
		pHead = newNode;
	}
	else {
		node *newNode = new node(recordN, idNum, name, email, unit, program, level);
		newNode->setPNext(pHead);
		pHead = newNode;
	}
}

void list::deleteRecursive(node *next) {
	if (next != nullptr) {
		deleteRecursive(next->getPNext());
		delete next;
	}
}