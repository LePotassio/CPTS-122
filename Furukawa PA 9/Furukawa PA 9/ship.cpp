#include "ship.h"

ship::ship(string newName, int newPower, int newSpeed, int newHealthMax, sf::Texture newTexture) : Sprite(newTexture) {
	name = newName;
	power = newPower;
	speed = newSpeed;
	healthMax = newHealthMax;
	health = newHealthMax;
	crewSize = 0;
	money = 0;
}
ship::ship(sf::Texture newTexture) : sf::Sprite(newTexture) {//most likely newtexture portion dn work, use setTexture instead
	name = "default";
	power = 1;
	speed = 1;
	healthMax = 5;
	health = 5;
	crewSize = 0;
	money = 0;
}
ship::ship() {
	name = "default";
	power = 1;
	speed = 1;
	healthMax = 5;
	health = 5;
	crewSize = 0;
	money = 0;
}
ship::~ship() {

}

string ship::getName() {
	return name;
}
int ship::getPower() {
	return power;
}
int ship::getSpeed() {
	return speed;
}
int ship::getHealthMax() {
	return healthMax;
}
int ship::getHealth() {
	return health;
}
int ship::getMoney() {
	return money;
}
person *ship::getCrew() {
	return crew;
}
int ship::getCrewSize() {
	return crewSize;
}

void ship::setName(string newName) {
	name = newName;
}
void ship::setPower(int newPower) {
	power = newPower;
}
void ship::setSpeed(int newSpeed) {
	speed = newSpeed;
}
void ship::setHealthMax(int newHealthMax) {
	healthMax = newHealthMax;
}
void ship::setHealth(int newHealth) {
	health = newHealth;
}

void ship::setMoney(int newMoney) {
	money = newMoney;
}

void ship::addMoney(int addAmount) {
	money += addAmount;
}
bool ship::addCrew(string newName) {
	if (crewSize < 4) {
		crewSize++;
		person pers(newName, 10);
		crew[crewSize - 1] = pers;
		return true;
	}
	else {
		return false;
	}
}
void ship::killCrew(int crewNum) {
	//
}
void ship::setCrewSize(int newCrewSize) {

}
void ship::addCrewSize(int addAmount) {

}


//void ship::draw() {

//}
