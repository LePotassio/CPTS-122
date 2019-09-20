#include "iostream"
#include "fstream"
#include "string"
#include "node.h"

class list {
private:
	node *pHead;
public:
	list();
	~list();

	node *getPHead();
	void setPHead(node *newPHead);

	void insertFront(std::string recordN, int idNum, std::string name, std::string email, std::string unit, std::string program, std::string level);
	void deleteRecursive(node *next);
};