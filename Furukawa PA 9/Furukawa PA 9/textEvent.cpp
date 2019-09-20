#include "textEvent.h"

textEvent::textEvent(string prompt, ship &player, sf::RenderWindow &window) : eventS(prompt, player, window) {

}

void textEvent::addMoneyEvent(int addAmount) {
	player.addMoney(addAmount);
	printPrompt();
}



void textEvent::healORDealDmg(int dmgAmount, int crewNum) {
	//person crew[4] = player.getCrew();
	player.getCrew()[crewNum].addORsubHealth(dmgAmount);
}

void textEvent::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	
}

//add crew event