#include <iostream>
#include <string>

using std::string;

class sneknode {
public:
	sneknode(string newsnek);
	sneknode();
	~sneknode();
	string getsnekS();
	void editsnekS(string newsnek);
	sneknode *getsnext();
	void editsnext(sneknode *newsnek);

private:
	string snekS;
	sneknode *snext;

};