#include <iostream>
#include <string>

#include "QueueNode.h"

QueueNode::QueueNode(std::string line, int cNum) {
	this->pData = new Data(line, cNum);
	this->pNext = nullptr;
}
QueueNode::~QueueNode() {
	delete this->pData;
}

Data *QueueNode::getPData() {
	return this->pData;
}
void QueueNode::setPData(Data *newPData) {
	this->pData = newPData;
}

QueueNode *QueueNode::getPNext() {
	return this->pNext;
}
void QueueNode::setPNext(QueueNode *newPNext) {
	this->pNext = newPNext;
}

void QueueNode::printqueuenode(std::string line) {
	std::cout << " Customer: " << pData->getCustomerNumber() << std::endl;
}