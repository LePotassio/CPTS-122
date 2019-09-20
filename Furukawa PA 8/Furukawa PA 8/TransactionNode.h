#include "BSTNode.h"
#include <iostream>
#include <string>

class TransactionNode : public BSTNode {
public:
	TransactionNode(std::string &newData, int newUnit);
	TransactionNode();
	~TransactionNode();

	int getMUnits();
	void setMUnits(int newMUnits);

	void printData();
protected:


private:
	int mUnits;

};