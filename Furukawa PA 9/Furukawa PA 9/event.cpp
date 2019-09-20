#include "event.h"

//eventS::eventS() : windowI(){
	//prompt = "";
//}
eventS::eventS(string newPrompt, ship &newPlayer, sf::RenderWindow &window) : windowI(window)  {
	prompt = newPrompt;
	player = newPlayer;
}
eventS::~eventS() {

}

string eventS::getPrompt() {
	return prompt;
}
void eventS::setPrompt(string newPrompt) {
	prompt = newPrompt;
}

ship eventS::getShip() {
	return player;
}
void eventS::setShip(ship newShip) {
	player = newShip;
}
void eventS::printPrompt() {
	sf::Text promptT;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	promptT.setFont(font);
	promptT.setPosition(200, 600);
	promptT.setString(prompt);
	windowI.draw(promptT);
}