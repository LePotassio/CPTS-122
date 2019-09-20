#include "person.h"


person::person(string newName, int healthStart) {
	name = newName;
	health = healthStart;
}
person::person() {
	name = "";
	health = 5;
}
person::~person() {

}

string person::getName() {
	return name;
}
void person::setName(string newName) {
	name = newName;
}

int person::getHealth() {
	return health;
}
void person::setHealth(int newHealth) {
	health = newHealth;
}
void person::addORsubHealth(int addAmount) {
	health += addAmount;
}