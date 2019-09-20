#include "iostream"
#include "fstream"
#include "string"
#include "stack.h"

class node {
private:
	node *pNext;
	stack *attendance;
	std::string recordN;
	int idNum;
	std::string name;
	std::string email;
	std::string unit;
	std::string program;
	std::string level;
public:
	node(std::string recordN, int idNum, std::string name, std::string email, std::string unit, std::string program, std::string level);
	~node();

	node *getPNext();
	stack *getAttendace();

	void setPNext(node *newPNext);
	void setAttendace(stack *newAttendace);

	std::string getRecordN();
	int getIdNum();
	std::string getName();
	std::string getEmail();
	std::string getUnit();
	std::string getProgram();
	std::string getLevel();

	void setRecordN(std::string newRecordN);
	void setIdNum(int newIdNum);
	void setName(std::string newName);
	void setEmail(std::string newEmail);
	void setUnit(std::string newUnit);
	void setProgram(std::string newProgram);
	void setLevel(std::string newLevel);

};