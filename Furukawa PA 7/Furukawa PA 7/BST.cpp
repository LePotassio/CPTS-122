#include "BST.h"

BST::BST() {
	pRoot = nullptr;
}
BST::BST(const bool isMorse) {
	pRoot = nullptr;
	std::ifstream infile;
	infile.open("MorseTable.txt");
	while (!infile.eof()) {
		std::string input;
		getline(infile, input);
		this->insertNode(input);
	}
	infile.close();
}
BST::BST(const BST &copy) {

}
BST::~BST() {
	destroyTree(pRoot);
}
void BST::destroyTree(BSTNode *next) {
	if (next != nullptr) {
		destroyTree(next->getLeft());
		destroyTree(next->getRight());
		delete next;
	}
}
BSTNode& BST::getRoot() {
	return *pRoot;
}
void BST::setRoot(BSTNode *newRoot) {
	pRoot = newRoot;
}

void BST::insertNode(std::string newData) {
	insertNode(pRoot, newData);
}
void BST::insertNode(BSTNode*& subRoot, std::string newData) {
	std::string newascii;
	std::stringstream ss(newData);
	getline(ss, newascii, '_');
	if (isEmpty()) {
		BSTNode *newNode = new BSTNode(newData);
		pRoot = newNode;
		return;
	}

	if (subRoot->getASCII() > newascii) {
		if (subRoot->getLeft() == nullptr) {
			BSTNode *newNode = new BSTNode(newData);
			subRoot->setLeft(newNode);
		}
		else {
			insertNode(subRoot->getLeft(), newData);
		}
	}
	else if (subRoot->getASCII() < newascii) {
		if (subRoot->getRight() == nullptr) {
			BSTNode *newNode = new BSTNode(newData);
			subRoot->setRight(newNode);
		}
		else {
			insertNode(subRoot->getRight(), newData);
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

void BST::inOrderTraversal(BSTNode *next) {//use me as print tree
	if (next->getLeft() != nullptr) {
		inOrderTraversal(next->getLeft());
	}
	std::cout << next->getData() << std::endl;
	if (next->getRight() != nullptr) {
		inOrderTraversal(next->getRight());
	}
}
void BST::preOrderTraversal(BSTNode *next) {
	std::cout << next->getData() << std::endl;
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
	std::cout << next->getData() << std::endl;
}

bool BST::isEmpty() {
	if (pRoot == nullptr) {
		return true;
	}
	return false;
}

void BST::convertFile() {
	std::ifstream infile;
	infile.open("Convert.txt");

	while (!infile.eof()) {
		std::string input;
		getline(infile, input);

		
		for (int c = 0; c < input.size(); ++c) {
			std::cout << searchTree(input[c]) << " ";
		}
		std::cout << "\n";
	}
	infile.close();
}
std::string BST::searchTree(char search) {
	return searchTree(pRoot, search);
}
std::string BST::searchTree(BSTNode *next, char search) {
	if (search == ' ') {
		return " ";
	}


	search = toupper(search);
	std::string ssearch(1, search);//https://stackoverflow.com/questions/12692221/deleting-n-first-chars-from-string
	if (next->getASCII() == ssearch) {
		std::string result = next->getData();
		result.erase(0, 2);
		return result;
	}
	if (next->getLeft() != nullptr && ssearch < next->getASCII()) {
		return searchTree(next->getLeft(), search);
	}
	if (next->getRight() != nullptr && ssearch > next->getASCII()) {
		return searchTree(next->getRight(), search);
	}
	return " ";
}

std::ostream& operator<<(std::ostream &lhs, BST &rhs) {
	rhs.inOrderTraversal();
	return lhs;
}