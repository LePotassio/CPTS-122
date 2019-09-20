#include "Queue.h"

Queue::Queue() {
	this->pHead = nullptr;
	this->pTail = nullptr;
}
Queue::~Queue() {
	QueueNode *itr = pHead;
	QueueNode *temp = pHead;
	while (itr != nullptr) {
		temp = itr;
		itr = itr->getPNext();
		delete temp;
	}
}

QueueNode *Queue::getPHead() {
	return this->pHead;
}
QueueNode *Queue::getPTail() {
	return this->pTail;
}

void Queue::setPHead(QueueNode *newPHead) {
	this->pHead = newPHead;
}
void Queue::setPTail(QueueNode *newPTail) {
	this->pTail = newPTail;
}

bool Queue::isEmpty() {
	if (pHead == nullptr) {
		return true;
	}
	return false;
}
void Queue::enqueue(std::string line, int cNum) {
	QueueNode *newQueueNode = nullptr;
	newQueueNode = new QueueNode(line, cNum);
	if (isEmpty()) {
		this->pHead = this->pTail = newQueueNode;
	}
	else {
		this->pTail->setPNext(newQueueNode);
		this->pTail = newQueueNode;
	}
}
void Queue::dequeue() {
	if (isEmpty()){
		return;
	}
	else if (pHead == pTail) {
		delete pHead;
		pHead = nullptr;
		pTail = nullptr;
	}
	else {
		QueueNode *temp = pHead;
		pHead = pHead->getPNext();
		delete temp;
	}
}
void Queue::printqueue(std::string line) {
	QueueNode *itr = pHead;
	while (itr != nullptr) {
		std::cout << "-";
		//itr->printqueuenode(line);
		//itr = itr->getPNext();

		std::cout << " Customer: " << itr->getPData()->getCustomerNumber() << std::endl;
		itr = itr->getPNext();
	}
}