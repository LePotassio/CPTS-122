#include "ExercisePlan.h"

ExercisePlan::ExercisePlan() {
	this->goal = 0;
	this->name = "";
	this->date = "";
}
ExercisePlan::ExercisePlan(int newgoal, string newname, string newdate) {
	this->goal = newgoal;
	this->name = newname;
	this->date = newdate;
}
ExercisePlan::ExercisePlan(ExercisePlan &copy) {
	goal = copy.getGoal();
	name = copy.getName();
	date = copy.getDate();
}
ExercisePlan::~ExercisePlan() {

}
int ExercisePlan::getGoal() {
	return this->goal;
}
string ExercisePlan::getName() {
	return this->name;
}

string ExercisePlan::getDate() {
	return this->date;
}


void ExercisePlan::setGoal(int newgoal) {
	this->goal = newgoal;
}

void ExercisePlan::setName(string newname) {
	this->name = newname;
}

void ExercisePlan::setDate(string newdate) {
	this->date = newdate;
}

void ExercisePlan::editGoal() {
	cout << "Enter a new goal" << endl;
	cin >> this->goal;
	cout << *this << endl;
}
void ExercisePlan::editName() {
	cout << "Enter a new name" << endl;
	getchar();
	getline(cin, this->name);
	cout << *this << endl;
}
void ExercisePlan::editDate() {
	cout << "Enter a new date" << endl;
	getchar();
	getline(cin, this->date);
	cout << *this << endl;
}

ostream & operator <<(ostream &lhs, ExercisePlan &rhs) {
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoal() << endl;
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}

fstream & operator <<(fstream &lhs, ExercisePlan &rhs) {
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoal() << endl;
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}

fstream & operator >> (fstream &lhs, ExercisePlan &rhs) {
	int goal;
	string date;
	string name;
	string blankLine;

	getline(lhs, name);
	lhs >> goal >> date;

	rhs.setName(name);
	rhs.setDate(date);
	rhs.setGoal(goal);

	getline(lhs, blankLine);
	getline(lhs, blankLine);
	return lhs;
}