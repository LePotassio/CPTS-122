#include "BST.h"
#include <fstream>

class DataAnalysis {
public:
	void runAnalysis();
protected:

private:
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;

	void opener();
	void reader(std::string &units, std::string &type, std::string &transaction);
	void looper();
	void inserter();
	void printTrends();
 };