#include "BSTNode.h"

BSTNode::BSTNode() {
	data = "";
	pLeft = nullptr;
	pRight = nullptr;
}
BSTNode::BSTNode(std::string &newData) {
	data = newData;
	pLeft = nullptr;
	pRight = nullptr;
}
BSTNode::~BSTNode() {

}

std::string BSTNode::getData() {
	return data;
}
BSTNode*& BSTNode::getLeft() {
	return pLeft;
}
BSTNode*& BSTNode::getRight() {
	return pRight;
}

void BSTNode::setData(std::string &newData) {
	data = newData;
}
void BSTNode::setLeft(BSTNode *newLeft) {
	pLeft = newLeft;
}
void BSTNode::setRight(BSTNode *newRight) {
	pRight = newRight;
}