#include "sneknode.h"


sneknode::sneknode(string newsnek) {
	this->snekS = newsnek;
	this->snext = nullptr;
}
sneknode::sneknode() {
	this->snekS = "";
	this->snext = nullptr;
}
sneknode::~sneknode() {

}
string sneknode::getsnekS() {
	return this->snekS;
}
void sneknode::editsnekS(string newsnek) {
	this->snekS = newsnek;
}
sneknode* sneknode::getsnext() {
	return this->snext;
}
void sneknode::editsnext(sneknode *newsnek) {
	this->snext = newsnek;
}