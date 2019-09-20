#include "statChange.h"
#include <sstream>

class battleHappen : public happen {
private:
	ship *enemyShipP;
	ship *player;
	sf::Text *text;
	sf::Text *statusT;
	sf::Text *statusE;
	sf::Font font;
	sf::Sprite *sprite;
	std::string message;
	sf::Text *hit;
	sf::Text *miss;
	sf::Text *hitE;
	sf::Text *missE;
	sf::Sprite *backGround;
	sf::Text *dayT;
	int reward;
public:
	battleHappen(ship *player, std::string prompt, std::string fileName, ship *enemyShip, sf::Text &status, sf::Sprite &back, sf::Text &day, int rewardAm) {
		reward = rewardAm;
		enemyShipP = enemyShip;
		backGround = &back;
		drawables.push_back(backGround);
		dayT = &day;
		drawables.push_back(dayT);
		message = prompt;
		//std::cout << "Player memory location : " << &player << std::endl;
		this->player = player;
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
		
		statusT = &status;
		drawables.push_back(statusT);
		statusE = new sf::Text;
		statusE->setFont(font);
		statusE->setPosition(300,0);
		statusE->setCharacterSize(22);
		drawables.push_back(statusE);
		drawables.push_back(player);
		
	}

	bool update(sf::RenderWindow &window, bool &winner) {
		bool first = true;
		enemyShipP->setHealth(enemyShipP->getHealthMax());
		miss = new sf::Text;
		miss->setString("You Missed!");
		miss->setFont(font);
		miss->setPosition(300, 350);
		//drawables.push_back(miss);

		hit = new sf::Text;
		hit->setString("You Hit!");
		hit->setFont(font);
		hit->setPosition(300, 350);
		//drawables.push_back(hit);

		missE = new sf::Text;
		missE->setString("Enemy Missed!");
		missE->setFont(font);
		missE->setPosition(300, 400);

		hitE = new sf::Text;
		hitE->setString("Enemy Hit!");
		hitE->setFont(font);
		hitE->setPosition(300, 400);

		sf::Text result;
		result.setFont(font);
		result.setPosition(400, 400);

		//if (enemyShip->getHealth() != 0) {
			//fight or run? winner decided on power? run % decided on speed? lose fight lose health?
			bool isHit = false;
			bool isHitE = false;
			bool isEnd = true;
			while (player->getHealth() > 0 && enemyShipP->getHealth() > 0) {
				sf::Event event;
				//std::cout << "Battle In" << std::endl;
				while (window.pollEvent(event))
				{
					//std::cout << "Battle In" << std::endl;
					if (event.type == sf::Event::KeyPressed) {
						if (event.key.code == sf::Keyboard::Return) {
							//attack
							//std::cout << "Battle In" << std::endl;
							first = false;
							int roll = rand() % 100 + 1;
							
							if (roll > enemyShipP->getSpeed()) {
								//hit
								isHit = true;
								enemyShipP->setHealth(enemyShipP->getHealth() - player->getPower());
							}
							else {
								//dodge
								isHit = false;
							}
							
							roll = rand() % 100 + 1;
							if (roll > player->getSpeed()) {
								//hit
								isHitE = true;
								player->setHealth(player->getHealth() - enemyShipP->getPower());
							}
							else {
								//dodge
								isHitE = false;
							}
						}
					}
				}
				window.clear();
				updateStat(*player);
				updateStatE(*enemyShipP);
				window.draw(*this);
				if (!first) {
					if (isHit) {
						window.draw(*hit);
					}
					else {
						window.draw(*miss);
					}
					if (isHitE) {
						window.draw(*hitE);
					}
					else {
						window.draw(*missE);
					}
				}
				window.display();
			}
			while (isEnd) {
				sf::Event eventE;
				while (window.pollEvent(eventE))
				{
					if (isEnd) {
						if (player->getHealth() > 0) {
							result.setString("You Win!");
							winner = true;//pauses here too
							if (eventE.type == sf::Event::KeyPressed) {
								if (eventE.key.code == sf::Keyboard::Return) {
									isEnd = false;
									//window.draw(result);
								}
							}
						}
						else {
							winner = false;
							result.setString("You Lose!");
							winner = true;//pauses here too
							if (eventE.type == sf::Event::KeyPressed) {
								if (eventE.key.code == sf::Keyboard::Return) {
									isEnd = false;
									//window.draw(result);
								}
							}
						}
					}
				}
				window.clear();
				updateStat(*player);
				updateStatE(*enemyShipP);
				window.draw(*this);
				window.draw(result);
				window.display();
				//window.clear();
			}
			//return false;
		//}
		//return true;
		player->setMoney(player->getMoney() + reward);
		return true;
	}
	
	bool updateStat(ship &player) {
		std::stringstream stats;
		stats << "Money:\n" << player.getMoney() << "\nHealth:\n" << player.getHealth() << "/" << player.getHealthMax() << "\nSpeed:\n" << player.getSpeed() << "\nPower:\n" << player.getPower() << "\n\0";
		string temp = stats.str();
		statusT->setString(temp);

		//TODO: do the stuff that this even should do,each time update is called you should progress one step and return true when done with the entire event

		return true;
	}
	bool updateStatE(ship &enemy) {
		std::stringstream stats;
		stats << "Reward:\n" << reward << "\nHealth:\n" << enemy.getHealth() << "/" << enemy.getHealthMax() << "\nSpeed:\n" << enemy.getSpeed() << "\nPower:\n" << enemy.getPower() << "\n\0";
		string temp = stats.str();
		statusE->setString(temp);

		//TODO: do the stuff that this even should do,each time update is called you should progress one step and return true when done with the entire event

		return true;
	}
	bool update() {
		update();
		return true;
	}
	
};
