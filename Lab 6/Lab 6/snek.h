#include <iostream>
#include "sneknode.h"


class snek {
public:
	snek();
	~snek();

	bool issnekshed();
	bool ensnek(string newsnekS);
	string desnek();
	void printsnekre(sneknode *it);

	sneknode *snek::getsnekhead();
private:	
	sneknode *snekhead;
	sneknode *snektail;
	
};