#include "menu.h"

menu::menu() {

}
menu::~menu() {

}
void menu::runMenu() {
	int option = 0;
	while (option != 7) {
		std::cout << "1.Import course list\n2.Load master list\n3.Store master list\n4.Mark absences\n5.Edit absences\n6.Generate report\n7.ExitEnter 1-7: " << std::endl;
		std::cin >> option;
		switch (option) {
		case 1:
			import();
			break;
		case 2:
			load();
			break;
		case 3:
			store();
			break;
		case 4:
			mark();
			break;
		case 5:
			edit();
			break;
		case 6:
			generate();
			break;
		}
	}
	exit();
}

void menu::import() {
	std::string input;
	std::ifstream infile;
	infile.open("classList.csv");
	getline(infile, input);
	std::string recordN;
	int idNum;
	std::string idNumS;
	std::string name;
	std::string name2;
	std::string email;
	std::string unit;
	std::string program;
	std::string level;
	while (!infile.eof()) {
		//getline(infile, input, ',');//num line
		getline(infile, recordN, ',');
		getline(infile, idNumS, ',');
		idNum = stoi(idNumS);
		getline(infile, name, ',');
		getline(infile, name2, ',');
		name.append(",");
		name.append(name2);
		getline(infile, email, ',');
		getline(infile, unit, ',');
		getline(infile, program, ',');
		getline(infile, level);
		master.insertFront(recordN, idNum, name, email, unit, program, level);
	}
	//master.insertFront(recordN, idNum, name, email, unit, program, level);
	infile.close();
}
void menu::load() {
	std::string input;
	std::ifstream infile;
	infile.open("master.txt");
	getline(infile, input);
	std::string recordN;
	int idNum;
	std::string idNumS;
	std::string name;
	std::string name2;
	std::string email;
	std::string unit;
	std::string program;
	std::string level;
	while (!infile.eof()) {
		getline(infile, recordN, ',');
		getline(infile, idNumS, ',');
		idNum = stoi(idNumS);
		getline(infile, name, ',');
		getline(infile, name2, ',');
		name.append(",");
		name.append(name2);
		getline(infile, email, ',');
		getline(infile, unit, ',');
		getline(infile, program, ',');
		getline(infile, level, ',');
		getline(infile, input);
	}
	master.insertFront(recordN, idNum, name, email, unit, program, level);
	infile.close();
}
void menu::store() {
	//int num = 1;
	std::ofstream outfile;
	outfile.open("master.txt");
	outfile << ", ID, Name, Email, Units, Program, Level\n";
	node *itr = master.getPHead();
	while (itr != nullptr) {
		//std::cout << itr->getProgram() << "," << itr->getLevel() << "\n";
		outfile << itr->getRecordN() << "," << itr->getIdNum() << "," << itr->getName() << "," << itr->getEmail() << "," << itr->getUnit() << "," << itr->getProgram() << "," << itr->getLevel() << "," << itr->getAttendace()->getInfoSize() << "\n";
		itr = itr->getPNext();
	}
	outfile.close();
}
void menu::mark() {
	node *itr = master.getPHead();
	int abs = 0;
	std::string currentDate = "";
	//sample code from spec
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	//std::cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << std::endl;
	currentDate.append(std::to_string(now->tm_year + 1900));
	currentDate.append("-");
	currentDate.append(std::to_string(now->tm_mon + 1));
	currentDate.append("-");
	currentDate.append(std::to_string(now->tm_mday));

	while (itr != nullptr) {
		std::cout << itr->getName() << " was absent? 1->yes 2->no\n";
		std::cin >> abs;
		if (abs == 1) {
			itr->getAttendace()->push(currentDate);
		}
		itr = itr->getPNext();
	}
}
void menu::edit() {
	int idNum = 0;
	std::string date = "";
	std::cout << "Please enter a idNum to edit: ";
	std::cin >> idNum;
	std::cout << "Please enter a date to edit: ";
	std::cin >> date;
	int newAtt;
	std::cout << "Please enter a new was absent. 1->yes 2->no";
	std::cin >> newAtt;

	node *itr = master.getPHead();
	node *itr2 = master.getPHead();
	while (itr->getPNext() != nullptr) {
		if (idNum == itr->getIdNum()) {
			for (int c = 0; c < itr->getAttendace()->getInfoSize(); ++c) {
				
				if (newAtt == 1) {
					itr->getAttendace()->push(date);
					break;
				}
				else if (newAtt == 2){
					if (itr->getAttendace()->cheatPeek(c) == date) {
						if (itr2->getIdNum() == itr->getIdNum()) {

						}
						else {
							while (itr2->getPNext()->getIdNum() != itr->getIdNum()) {
								itr2 = itr2->getPNext();
							}
							itr2->setPNext(itr->getPNext());
						}
						itr->getAttendace()->pop();
					}
				}
			}
		}
		itr = itr->getPNext();
	}
}
void menu::generate() {
	int option = 0;
	while (option != 1 && option != 2 && option != 3) {
		std::cout << "\n1.All recent\n2.Select recent\n3.Exit.Enter 1 or 2 or 3: " << std::endl;
		std::cin >> option;
		switch (option) {
		case 1:
			generateAll();
			break;
		case 2:
			generateSelect();
			break;
		}
	}
}
void menu::generateAll() {
	std::ofstream outfile;
	outfile.open("recentAll.text");

	node * itr = master.getPHead();
	while (itr != nullptr) {
		if (itr->getAttendace()->isEmpty()) {
			outfile << itr->getName() << ": None\n";
		}
		else {
			outfile << itr->getName() << ": " << itr->getAttendace()->peek() << "\n";
		}
		itr = itr->getPNext();
	}
	outfile.close();
}
void menu::generateSelect() {
	int min = 0;
	std::cout << "Select # absences min: ";
	std::cin >> min;

	std::ofstream outfile;
	outfile.open("recentSelect.text");

	node * itr = master.getPHead();
	while (itr != nullptr) {
		if (itr->getAttendace()->getInfoSize() >= min) {
			outfile << itr->getName() << ": " << itr->getAttendace()->peek() << "\n";
		}
		itr = itr->getPNext();
	}
	outfile.close();
}
void menu::exit() {
	std::cout << "Bye" << std::endl;
}