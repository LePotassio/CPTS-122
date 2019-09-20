#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "event.h"

using std::string;
class textEvent : public eventS {
private:

public:
	textEvent(string prompt, ship &player, sf::RenderWindow &window);

	void addMoneyEvent(int addAmount);
	
	//void printPrompt();

	void healORDealDmg(int dmgAmount, int crewNum);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};