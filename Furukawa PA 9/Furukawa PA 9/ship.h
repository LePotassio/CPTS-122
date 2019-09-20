#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "person.h"

using std::string;
class ship : public sf::Sprite /*: private sf::Drawable*/ {
private:
	string name;
	int power;
	int speed;
	int healthMax;
	int health;
	int money;

	sf::Texture texture;
	//texture.loadFromFile("te fuk.png");
	//shape2.setPosition(10, 10);
	//sf::Sprite P1(texture);

	person crew[4];
	int crewSize;
public:
	ship(string newName, int newPower, int newSpeed, int newHealthMax, sf::Texture newTexture);
	ship(sf::Texture newTexture);
	ship();
	~ship();

	string getName();
	int getPower();
	int getSpeed();
	int getHealthMax();
	int getHealth();
	int getMoney();
	person *getCrew();
	int getCrewSize();

	void setName(string newName);
	void setPower(int newPower);
	void setSpeed(int newSpeed);
	void setHealthMax(int newHealthMax);
	void setHealth(int newHealth);
	void setMoney(int newMoney);
	bool addCrew(string newName);
	void killCrew(int crewNum);
	void setCrewSize(int newCrewSize);
	void addCrewSize(int addAmount);

	void addMoney(int addAmount);


	void printCrew();
	//virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	//void load();
};