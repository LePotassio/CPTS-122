#include "snek.h"

snek::snek() {
	snekhead = nullptr;
	snektail = nullptr;
}
snek::~snek() {

}

bool snek::issnekshed() {
	if (snekhead == nullptr) {
		return true;
	}
	return false;
}
bool snek::ensnek(string newsnekS) {
	sneknode *elnood = new sneknode(newsnekS);
	if (elnood == nullptr) {
		return false;
	}
	if (issnekshed()) {
		snektail = elnood;
		snekhead = elnood;
		return true;
	}
	snektail->editsnext(elnood);
	snektail = elnood;
	return true;
}
string snek::desnek() {
	if (issnekshed() == true) {
		return nullptr;
	}
	sneknode *temp = snekhead;
	string snekS = snekhead->getsnekS();
	snekhead = snekhead->getsnext();
	delete temp;
	return snekS;
}
void snek::printsnekre(sneknode *it) {
	if (it == nullptr) {
		return;
	}
	std::cout << it->getsnekS() << std::endl;
	printsnekre(it->getsnext());
}

sneknode *snek::getsnekhead() {
	return snekhead;
}