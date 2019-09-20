#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


class BSTNode {
public:
	BSTNode();
	BSTNode(std::string &newData);
	~BSTNode();

	std::string getData();
	std::string getASCII();
	BSTNode*& getLeft();
	BSTNode*& getRight();

	void setData(std::string &newData);
	void setLeft(BSTNode *newLeft);
	void setRight(BSTNode *newRight);

private:
	std::string data;
	BSTNode *pLeft;
	BSTNode *pRight;
};