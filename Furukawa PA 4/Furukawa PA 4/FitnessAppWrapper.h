#pragma once

#include <iostream>
#include <fstream>
//#include <string>
#include "ExercisePlan.h"
#include "DietPlan.h"

//using std::string; //cant include here? (double include?)
using std::cin;
using std::cout;
using std::endl;
using std::fstream;


class Fit {
public:
	Fit();
	~Fit();

	void runApp();
	void displayMenu();
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);
	void loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);
	void displayDailyPlan(DietPlan &plan);
	void displayWeeklyPlan(DietPlan weeklyPlan[]);
	void displayDailyPlan(ExercisePlan &plan);
	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);

	void Fit::storeWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void Fit::storeWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);
	void Fit::storeDailyPlan(fstream &fileStream, DietPlan &plan);
	void Fit::storeDailyPlan(fstream &fileStream, ExercisePlan &plan);

	void Fit::editDailyPlan(DietPlan weeklyPlan[]);
	void Fit::editDailyPlan(ExercisePlan weeklyPlan[]);

private:
	//DietPlan Array
	DietPlan Diets[7];
	//Exercise Plan Array
	ExercisePlan Exercises[7];

	fstream dietfile;
	fstream exercisefile;
};
