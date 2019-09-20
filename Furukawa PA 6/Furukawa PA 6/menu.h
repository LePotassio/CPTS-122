#include "iostream"
#include "fstream"
#include "string"
#include "list.h"
#include "time.h"

class menu {
private:
	list master;
public:
	menu();
	~menu();
	void runMenu();
	
	void import();
	void load();
	void store();
	void mark();
	void edit(); 
	void generate();

	void generateAll();
	void generateSelect();

	void exit();
};