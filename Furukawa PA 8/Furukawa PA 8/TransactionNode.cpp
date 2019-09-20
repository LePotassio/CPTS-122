#include "TransactionNode.h"

TransactionNode::TransactionNode(std::string &newData, int newUnit) : BSTNode(newData) {
	mUnits = newUnit;
}
TransactionNode::TransactionNode() : BSTNode() {
	mUnits = 0;
}
TransactionNode::~TransactionNode() {

}

int TransactionNode::getMUnits() {
	return mUnits;
}
void TransactionNode::setMUnits(int newMUnits) {
	mUnits = newMUnits;
}

void TransactionNode::printData() {
	std::cout << mUnits << " " << getData() << std::endl;
}