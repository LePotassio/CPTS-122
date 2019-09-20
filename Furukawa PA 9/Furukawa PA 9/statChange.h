#pragma once


#include "happen.h"
//#include "ship.h"
#include <SFML/Graphics.hpp>
typedef enum statType {health = 1, power = 2, speed = 3, maxHealth = 4, money = 5} StatType;
class statChange : public happen {
private:
	ship *player;
	StatType type;
	int amount;
	sf::Text *text;
	//sf::Text *status;
	sf::Font font;
	sf::Sprite *sprite;
	std::string message;

	void doChange() {
		std::string nope = "";
		switch (type) {
		case health:
			player->setHealth(player->getHealth() + amount);
			if (player->getHealth() > player->getHealthMax()) {
				player->setHealth(player->getHealthMax());
			}
			break;
		case power:
			player->setPower(player->getPower() + amount);
			if (player->getPower() > 10) {
				player->setPower(10);
			}
			if (player->getPower() < 0) {
				player->setPower(0);
			}
			break;
		case speed:
			player->setSpeed(player->getSpeed() + amount);
			if (player->getSpeed() > 90) {
				player->setSpeed(90);
			}
			if (player->getSpeed() < 0) {
				player->setSpeed(0);
			}
			break;
		case maxHealth:
			player->setHealthMax(player->getHealthMax() + amount);//Dont Use this plox
			break;
		case money:
			player->setMoney(player->getMoney() + amount);
			if (player->getMoney() < 0) {
				player->setMoney(0);
				nope = "\n(You cannot have negative moneys)";
			} 
			break;
		}
		text->setString(message + nope);

	}
protected:
	
public:
	ship& getPlayer() {
		return *player;
	}
	statChange(StatType type, int amount, ship *player, std::string prompt, std::string fileName) {
		message = prompt;
		//std::cout << "Player memory location : " << &player << std::endl;
		this->player = player;
		this->amount = amount;
		this->type = type;
		sprite = new sf::Sprite();
		sprite->setPosition(600, 100);
		sf::Texture * texture = new sf::Texture();
		texture->loadFromFile(fileName);
		sprite->setTexture(*texture);
		drawables.push_back(sprite);
		
		
		//TODO: create text objs and add to drawables
		//TODO: create+ add other relevent stuff to drawables
		text = new sf::Text();
		//status = new sf::Text();
		text->setString(prompt);
		font.loadFromFile("arial.ttf");
		//status->setFont(font);
		text->setFont(font);
		text->setPosition(450, 450);

		drawables.push_back(text);
		//drawables.push_back(status);

	}
	~statChange() {

	}

	

	bool update(sf::RenderWindow &window, bool &winner) {
		doChange();
		//TODO: do the stuff that this even should do,each time update is called you should progress one step and return true when done with the entire event

		return true;
	}
};