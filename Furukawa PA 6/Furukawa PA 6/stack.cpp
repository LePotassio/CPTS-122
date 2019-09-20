#include "stack.h"

stack::stack() {
	info = new std::string[100];
}
stack::~stack() {
	delete[] info;
}

void stack::push(std::string newString) {
	if (getInfoSize() != 100) {
		info[getInfoSize()] = newString;
	}
}
void stack::pop() {
	if (!isEmpty()) {
		info[getInfoSize() - 1] = "";
	}
}
std::string stack::peek() {
	if (!isEmpty()) {
		return info[getInfoSize() - 1];
	}
	return "";
}
std::string stack::cheatPeek(int loc) {
	if (!isEmpty()) {
		return info[loc];
	}
	return "";
}

bool stack::isEmpty() {
	if (info[0] == "") {
		return true;
	}
	return false;
}

int stack::getInfoSize() {
	int size = 0;
	while (info[size] != "") {
		size++;
	}
	return size;
}