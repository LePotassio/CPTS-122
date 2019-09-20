#include "Data.h"

Data::Data() {
	this->customerNumber = 0;
	this->serviceTime = 0;
	this->totalTime = 0;
}

Data::Data(std::string line, int cNum) {
	if (line == "Express") {
		serviceTime = rand() % 5 + 1;
	}
	else if (line == "Normal"){
		serviceTime = rand() % 6 + 3;
	}
	this->customerNumber = cNum;
	//this->serviceTime = 0;
	this->totalTime = 0;
}

Data::~Data() {

}

int Data::getCustomerNumber() {
	return this->customerNumber;
}

int Data::getServiceTime() {
	return this->serviceTime;
}

int Data::getTotalTime() {
	return this->totalTime;
}

void Data::setCustomerNumber(int newCustomerNumber) {
	this->customerNumber = newCustomerNumber;
}

void Data::setServiceTime(int newServiceTime) {
	this->serviceTime = newServiceTime;
}

void Data::setTotalTime(int newTotalTime) {
	this->totalTime = newTotalTime;
}

void Data::addTotalTime(int time) {
	totalTime += time;
}