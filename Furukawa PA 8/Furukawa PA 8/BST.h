#include "TransactionNode.h"
#include <iostream>
#include <string>


class BST {
public:
	BST();
	BST(const BST &copy);
	~BST();

	BSTNode& getRoot();
	void setRoot(BSTNode *newRoot);

	void insertNode(std::string newData, int newUnits);

	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();

	bool isEmpty();

	TransactionNode& findSmallest();
	TransactionNode& findLargest();
private:
	BSTNode *pRoot;
	void insertNode(BSTNode*& subRoot, std::string newData, int newUnits);

	void inOrderTraversal(BSTNode *next);
	void preOrderTraversal(BSTNode *next);
	void postOrderTraversal(BSTNode *next);

	void destroyTree(TransactionNode *next);
};

std::ostream& operator<<(std::ostream &lhs, BST &rhs);