#include "node.h"

node::node(std::string recordN, int idNum, std::string name, std::string email, std::string unit, std::string program, std::string level) {
	this->recordN = recordN;
	this->idNum = idNum;
	this->name = name;
	this->email = email;
	this->unit = unit;
	this->program = program;
	this->level = level;

	this->attendance = new stack;

	pNext = nullptr;
}
node::~node() {
	delete attendance;
}

node *node::getPNext() {
	return pNext;
}
stack *node::getAttendace() {
	return attendance;
}

void node::setPNext(node *newPNext) {
	pNext = newPNext;
}
void node::setAttendace(stack *newAttendace) {
	attendance = newAttendace;
}

std::string node::getRecordN() {
	return recordN;
}
int node::getIdNum() {
	return idNum;
}
std::string node::getName() {
	return name;
}
std::string node::getEmail() {
	return email;
}
std::string node::getUnit() {
	return unit;
}
std::string node::getProgram() {
	return program;
}
std::string node::getLevel() {
	return level;
}

void node::setRecordN(std::string newRecordN) {
	recordN = newRecordN;
}
void node::setIdNum(int newIdNum) {
	idNum = newIdNum;
}
void node::setName(std::string newName) {
	name = newName;
}
void node::setEmail(std::string newEmail) {
	email = newEmail;
}
void node::setUnit(std::string newUnit) {
	unit = newUnit;
}
void node::setProgram(std::string newProgram) {
	program = newProgram;
}
void node::setLevel(std::string newLevel) {
	level = newLevel;
}