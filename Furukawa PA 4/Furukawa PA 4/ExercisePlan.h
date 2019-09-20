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

class ExercisePlan {
public:
	ExercisePlan();
	ExercisePlan(int newgoal, string newname, string newdate);
	ExercisePlan(ExercisePlan &copy);
	~ExercisePlan();

	int getGoal();
	string getName();
	string getDate();

	void setGoal(int newgoal);
	void setName(string newname);
	void setDate(string newdate);

	void editGoal();//User input versions, also print using op overload
	void editName();
	void editDate();

private:
	int goal;
	string name;
	string date;
};


//
ostream & operator <<(ostream &lhs, ExercisePlan &rhs);
fstream & operator <<(fstream &lhs, ExercisePlan &rhs);
fstream & operator >>(fstream &lhs, ExercisePlan &rhs);