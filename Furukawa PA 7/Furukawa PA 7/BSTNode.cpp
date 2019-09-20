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
std::string BSTNode::getASCII() {
	std::string ascii;
	std::stringstream ss(data);
	getline(ss, ascii, '_');
	return ascii;
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