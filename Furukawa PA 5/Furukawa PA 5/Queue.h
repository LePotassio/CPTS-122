#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>

#include "QueueNode.h"

class Queue {
private:
	QueueNode *pHead;
	QueueNode *pTail;
public:
	Queue();
	~Queue();

	QueueNode *getPHead();
	QueueNode *getPTail();
	
	void setPHead(QueueNode *newPHead);
	void setPTail(QueueNode *newPTail);

	bool isEmpty();
	void enqueue(std::string line, int cNum);
	void dequeue();
	void printqueue(std::string line);

};