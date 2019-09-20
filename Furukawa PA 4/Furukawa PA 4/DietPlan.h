#pragma once

#include <iostream>//Include these in each header or included wrong?
#include <fstream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::ofstream;
using std::fstream;


class DietPlan {
public:
	DietPlan();
	DietPlan(int newcalories, string newname, string newdate);
	DietPlan::DietPlan(DietPlan &copy);
	~DietPlan();

	int getCalories();
	string getName();
	string getDate();

	void setCalories(int newcalories);
	void setName(string newname);
	void setDate(string newdate);

	void editCalories();//User input versions, also print using op overload
	void editName();
	void editDate();
private:
	int calories;
	string name;
	string date;
};

ostream & operator <<(ostream &lhs, DietPlan &rhs);
fstream & operator <<(fstream &lhs, DietPlan &rhs);
fstream & operator >> (fstream &lhs, DietPlan &rhs);