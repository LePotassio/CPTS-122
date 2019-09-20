#include "BSTNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


//BST and BSTNode Implemented by self in LAB 8
class BST {
public:
	BST();
	BST(const bool isMorse);
	BST(const BST &copy);
	~BST();

	BSTNode& getRoot();
	void setRoot(BSTNode *newRoot);

	void insertNode(std::string newData);

	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();

	bool isEmpty();


	void convertFile();
	std::string searchTree(char search);//uses helper in private section
	

private:
	BSTNode *pRoot;
	void insertNode(BSTNode*& subRoot, std::string newData);

	void inOrderTraversal(BSTNode *next);
	void preOrderTraversal(BSTNode *next);
	void postOrderTraversal(BSTNode *next);

	void destroyTree(BSTNode *next);

	std::string searchTree(BSTNode *next, char search);
};

std::ostream& operator<<(std::ostream &lhs, BST &rhs);