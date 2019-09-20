#include "BST.h"

BST::BST() {
	pRoot = nullptr;
}
BST::BST(const BST &copy) {

}
BST::~BST() {
	destroyTree((TransactionNode *)pRoot);
}
void BST::destroyTree(TransactionNode *next) {
	if (next != nullptr) {
		destroyTree((TransactionNode *)next->getLeft());
		destroyTree((TransactionNode *)next->getRight());
		delete next;
	}
}
BSTNode& BST::getRoot() {
	return *pRoot;
}
void BST::setRoot(BSTNode *newRoot) {
	pRoot = newRoot;
}

void BST::insertNode(std::string newData, int newUnits) {
	insertNode(pRoot, newData, newUnits);
}
void BST::insertNode(BSTNode*& subRoot, std::string newData , int newUnits) {
	if (isEmpty()) {
		BSTNode *newNode = new TransactionNode(newData, newUnits);
		pRoot = newNode;
		return;
	}

	if (((TransactionNode *)subRoot)->getMUnits() > newUnits) {
		if (subRoot->getLeft() == nullptr) {
			BSTNode *newNode = new TransactionNode(newData, newUnits);
			subRoot->setLeft(newNode);
		}
		else {
			insertNode(subRoot->getLeft(), newData, newUnits);
		}
	}
	else if (((TransactionNode *)subRoot)->getMUnits() < newUnits) {
		if (subRoot->getRight() == nullptr) {
			BSTNode *newNode = new TransactionNode(newData, newUnits);
			subRoot->setRight(newNode);
		}
		else {
			insertNode(subRoot->getRight(), newData, newUnits);
		}
	}
	else {
		//equal?
		std::cout << "Node already exists" << std::endl;
	}
}


void BST::inOrderTraversal() {
	inOrderTraversal(pRoot);
}
void BST::preOrderTraversal() {
	preOrderTraversal(pRoot);
}
void BST::postOrderTraversal() {
	postOrderTraversal(pRoot);
}

void BST::inOrderTraversal(BSTNode *next) {
	if (next->getLeft() != nullptr) {
		inOrderTraversal(next->getLeft());
	}
	std::cout << next->getData() << " " << ((TransactionNode *) next)->getMUnits() << std::endl;
	if (next->getRight() != nullptr) {
		inOrderTraversal(next->getRight());
	}
}
void BST::preOrderTraversal(BSTNode *next) {
	std::cout << next->getData() << " " << ((TransactionNode *) next)->getMUnits() << std::endl;
	if (next->getLeft() != nullptr) {
		preOrderTraversal(next->getLeft());
	}
	if (next->getRight() != nullptr) {
		preOrderTraversal(next->getRight());
	}
}
void BST::postOrderTraversal(BSTNode *next) {
	if (next->getLeft() != nullptr) {
		postOrderTraversal(next->getLeft());
	}
	if (next->getRight() != nullptr) {
		postOrderTraversal(next->getRight());
	}
	std::cout << next->getData() << " " << ((TransactionNode *) next)->getMUnits() << std::endl;
}

bool BST::isEmpty() {
	if (pRoot == nullptr) {
		return true;
	}
	return false;
}

TransactionNode& BST::findSmallest() {
	BSTNode* itr = pRoot;
	while (itr->getLeft() != nullptr) {
		itr = itr->getLeft();
	}
	return *(dynamic_cast <TransactionNode*>(itr));
}

TransactionNode& BST::findLargest() {
	BSTNode* itr = pRoot;
	while (itr->getRight() != nullptr) {
		itr = itr->getRight();
	}
	return *(dynamic_cast <TransactionNode*>(itr));
}

std::ostream& operator<<(std::ostream &lhs, BST &rhs) {
	rhs.inOrderTraversal();
	return lhs;
}