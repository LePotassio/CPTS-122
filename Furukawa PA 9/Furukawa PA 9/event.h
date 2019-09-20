#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "ship.h"

using std::string;
class eventS {
private:

protected:
	string prompt;
	sf::Text *promptT;
	sf::Font font;

	ship player;
	sf::RenderWindow &windowI;
public:
	//eventS();
	eventS(string newPrompt, ship &newPlayer, sf::RenderWindow &window);
	~eventS();
	//virtual void printPrompt() = 0;

	string getPrompt();
	void setPrompt(string newPrompt);

	ship getShip();
	void setShip(ship newShip);
	void printPrompt();
};