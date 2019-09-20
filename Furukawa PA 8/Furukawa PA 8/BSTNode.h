#include <iostream>
#include <string>


class BSTNode {
public:
	BSTNode();
	BSTNode(std::string &newData);
	virtual ~BSTNode();

	std::string getData();
	BSTNode*& getLeft();
	BSTNode*& getRight();

	void setData(std::string &newData);
	void setLeft(BSTNode *newLeft);
	void setRight(BSTNode *newRight);

	virtual void printData() = 0;
private:
	std::string data;
	BSTNode *pLeft;
	BSTNode *pRight;
};