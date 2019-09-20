#include "iostream"
#include "fstream"
#include "string"

class stack {
private:
	std::string *info;
public:
	stack();
	~stack();

	void push(std::string newString);
	void pop();
	std::string peek();
	std::string cheatPeek(int loc);
	bool isEmpty();

	int getInfoSize();
};