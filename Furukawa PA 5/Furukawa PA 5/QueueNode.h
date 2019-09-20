#include <iostream>
#include <string>

#include "Data.h"

class QueueNode {
private:
	Data *pData;
	QueueNode *pNext;
public:
	QueueNode(std::string line, int cNum);
	~QueueNode();

	Data *getPData();
	void setPData(Data *newPData);
	QueueNode *getPNext();
	void setPNext(QueueNode *newPNext);

	void printqueuenode(std::string line);
};