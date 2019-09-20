#include "FitnessAppWrapper.h"

Fit::Fit() {
	this->dietfile.open("dietplan.txt", fstream::in | fstream::out);

	this->exercisefile.open("exerciseplan.txt", fstream::in | fstream::out);
}

Fit::~Fit() {
	dietfile.close();
	exercisefile.close();
}

void Fit::runApp() {
	//new main
	//displayMenu();
	int option;
	//dietfile.open("dietplan.txt", std::ios::in);
	//exercisefile.open("exerciseplan.txt", std::ios::in);


	do {
		displayMenu();
		cout << "Please Make a Selection (1 - 9)" << endl;
		cin >> option;

		if (option < 1 || option > 9) {
			cout << "Please enter 1-9" << endl;
		}

		switch (option) {
		case 1://Load Weekly Diet
			loadWeeklyPlan(dietfile, Diets);
			system("cls");
			break;
		case 2://Load Weekly Exercise
			loadWeeklyPlan(exercisefile, Exercises);
			system("cls");
			break;
		case 3://Store Weekly Diet
			//dietfile.close();
			//dietfile.open("dietplan.txt", std::ios::out);
			storeWeeklyPlan(dietfile, Diets);
			//dietfile.close();
			//dietfile.open("dietplan.txt", std::ios::in);
			system("cls");
			break;
		case 4://Store Weekly Exercise
			//exercisefile.close();
			//exercisefile.open("exerciseplan.txt", std::ios::out);
			storeWeeklyPlan(exercisefile, Exercises);
			//exercisefile.close();
			//exercisefile.open("exerciseplan.txt", std::ios::in);
			system("cls");
			break;
		case 5://Display Weekly Diet
			system("cls");
			displayWeeklyPlan(Diets);
			break;
		case 6://Display Weekly Exercise
			system("cls");
			displayWeeklyPlan(Exercises);
			break;
		case 7://Edit Daily Diet
			editDailyPlan(Diets);
			system("cls");
			break;
		case 8://Edit Daily Exercise
			editDailyPlan(Exercises);
			system("cls");
			break;
		case 9://Exit
			system("cls");
			dietfile.close();
			exercisefile.close();
			cout << "Bye" << endl;
			break;
		}
	} while (option != 9);
}

void Fit::displayMenu() {
	std::cout << "1.Load weekly diet plan from file.\n2.Load weekly exercise plan from file.\n3.Store weekly diet plan to file.\n4.Store weekly exercise plan to file.\n5.Display weekly diet plan to screen.\n6.Display weekly exercise plan to screen.\n7.Edit daily diet plan.\n8.Edit daily exercise plan.\n9.Exit." << std::endl;
}

void Fit::loadDailyPlan(fstream &fileStream, DietPlan &plan) {
	fileStream >> plan;
}

void Fit::loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]) {
	for (int c = 0; c < 7; ++c) {
		loadDailyPlan(fileStream, weeklyPlan[c]);
	}
}

void Fit::loadDailyPlan(fstream &fileStream, ExercisePlan &plan) {
	fileStream >> plan;
}

void Fit::loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]) {
	for (int c = 0; c < 7; ++c) {
		loadDailyPlan(fileStream, weeklyPlan[c]);
	}
}

void Fit::displayDailyPlan(DietPlan &plan) {
	cout << plan;
}

void Fit::displayWeeklyPlan(DietPlan weeklyPlan[]) {
	for (int c = 0; c < 7; ++c) {
		displayDailyPlan(weeklyPlan[c]);
	}
}

void Fit::displayDailyPlan(ExercisePlan &plan) {
	cout << plan;
}

void Fit::displayWeeklyPlan(ExercisePlan weeklyPlan[]) {
	for (int c = 0; c < 7; ++c) {
		displayDailyPlan(weeklyPlan[c]);
	}
}


void Fit::storeWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]) {
	for (int c = 0; c < 7; ++c) {
		storeDailyPlan(fileStream, weeklyPlan[c]);
	}
}

void Fit::storeWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]) {
	for (int c = 0; c < 7; ++c) {
		storeDailyPlan(fileStream, weeklyPlan[c]);
	}
}

void Fit::storeDailyPlan(fstream &fileStream, DietPlan &plan) {
	fileStream << plan;
}

void Fit::storeDailyPlan(fstream &fileStream, ExercisePlan &plan) {
	fileStream << plan;
}


void Fit::editDailyPlan(DietPlan weeklyPlan[]) {
	int edit = 0;
	cout << "Which diet plan would you like to edit? (1-7)" << endl;
	do {
		cin >> edit;
	} while (edit < 1 || edit > 7);

	weeklyPlan[edit - 1].editName();
	weeklyPlan[edit - 1].editCalories();
	weeklyPlan[edit - 1].editDate();
}

void Fit::editDailyPlan(ExercisePlan weeklyPlan[]) {
	int edit = 0;
	cout << "Which exercise plan would you like to edit? (1-7)" << endl;
	do {
		cin >> edit;
	} while (edit < 1 || edit > 7);

	weeklyPlan[edit - 1].editName();
	weeklyPlan[edit - 1].editGoal();
	weeklyPlan[edit - 1].editDate();
}