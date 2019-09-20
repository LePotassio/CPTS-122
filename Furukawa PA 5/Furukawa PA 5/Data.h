#include <iostream>
#include <string>

class Data {
private:
	int customerNumber;
	int serviceTime;
	int totalTime;
public:
	Data();
	Data(std::string line, int cNum);
	~Data();

	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();

	void setCustomerNumber(int newCustomerNumber);
	void setServiceTime(int newServiceTime);
	void setTotalTime(int newTotalTime);

	void addTotalTime(int time);
};