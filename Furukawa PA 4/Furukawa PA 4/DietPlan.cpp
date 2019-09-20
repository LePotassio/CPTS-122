#include "DietPlan.h"

DietPlan::DietPlan() {
	this->calories = 0;
	this->name = "";
	this->date = "";
}
DietPlan::DietPlan(int newcalories, string newname, string newdate) {
	this->calories = newcalories;
	this->name = newname;
	this->date = newdate;
}
DietPlan::DietPlan(DietPlan &copy) {
	calories = copy.getCalories();
	name = copy.getName();
	date = copy.getDate();
}
DietPlan::~DietPlan() {

}
int DietPlan::getCalories() {
	return this->calories;
}
string DietPlan::getName() {
	return this->name;
}

string DietPlan::getDate() {
	return this->date;
}


void DietPlan::setCalories(int newcalories) {
	this->calories = newcalories;
}

void DietPlan::setName(string newname) {
	this->name = newname;
}

void DietPlan::setDate(string newdate) {
	this->date = newdate;
}

void DietPlan::editCalories() {
	cout << "Enter a new goal" << endl;
	cin >> this->calories;
	cout << *this << endl;
}
void DietPlan::editName() {
	cout << "Enter a new name" << endl;
	getchar();
	getline(cin, this->name);
	cout << *this << endl;
}
void DietPlan::editDate() {
	cout << "Enter a new date" << endl;
	getchar();
	getline(cin, this->date);
	cout << *this << endl;
}

ostream & operator <<(ostream &lhs, DietPlan &rhs) {
	lhs << rhs.getName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}

fstream & operator <<(fstream &lhs, DietPlan &rhs) {
	lhs << rhs.getName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}

fstream & operator >> (fstream &lhs, DietPlan &rhs) {
	int calories;
	string date;
	string name;
	string blankLine;

	getline(lhs, name);
	lhs >> calories >> date;

	rhs.setName(name);
	rhs.setDate(date);
	rhs.setCalories(calories);

	getline(lhs, blankLine);
	getline(lhs, blankLine);
	return lhs;
}