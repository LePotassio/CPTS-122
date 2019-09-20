#include "DataAnalysis.h"

void DataAnalysis::runAnalysis() {
	std::string in;

	opener();
	getline(mCsvStream, in, ',');
	getline(mCsvStream, in, ',');
	getline(mCsvStream, in);
	looper();
	printTrends();
}

void DataAnalysis::opener() {
	mCsvStream.open("data.csv");
}
void DataAnalysis::reader(std::string &units, std::string &type, std::string &transaction) {
	
	getline(mCsvStream, units, ',');
	getline(mCsvStream, type, ',');
	getline(mCsvStream, transaction);

}
void DataAnalysis::looper() {
	while (!mCsvStream.eof()) {
		inserter();
	}
	std::cout << "Purchased Tree" << std::endl;
	mTreePurchased.inOrderTraversal();
	std::cout << "\nSold Tree" << std::endl;
	mTreeSold.inOrderTraversal();
	std::cout << "\n";
}
void DataAnalysis::inserter() {
	std::string units;
	int iUnits = 0;
	std::string type;
	std::string transaction;
	reader(units, type, transaction);
	iUnits = stoi(units);
	if (transaction == "Purchased") {
		mTreePurchased.insertNode(type, iUnits);
	}
	else {
		mTreeSold.insertNode(type, iUnits);
	}
}
void DataAnalysis::printTrends() {
	TransactionNode temp;
	temp = mTreePurchased.findLargest();
	std::cout << "Most Purchased: " << temp.getData() << std::endl;
	temp = mTreeSold.findLargest();
	std::cout << "Most Sold: " << temp.getData() << std::endl;
	temp = mTreePurchased.findSmallest();
	std::cout << "Least Purchased: " << temp.getData() << std::endl;
	temp = mTreeSold.findSmallest();
	std::cout << "Least Sold: " << temp.getData() << std::endl;
}