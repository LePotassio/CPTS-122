#include "statChange.h"

#include <sstream>

class shopHappen : public happen {
private:
	ship *player;
	sf::Text *text;
	sf::Text *statusT;
	sf::Font font;
	sf::Sprite *sprite;
	std::string message;
	sf::Text *missE;
	sf::Sprite *backGround;
	sf::Text *dayT;
	int price1;
	int price2;
	int price3;
	int price4;
	int up1;
	int up2;
	int up3;
	int up4;
public:
	shopHappen(ship *player, std::string prompt, std::string fileName, sf::Text &status, sf::Sprite &back, sf::Text &day, int pricea, int priceb, int pricec, int priced, int upa, int upb, int upc, int upd) {
		up1 = upa;
		up2 = upb;
		up3 = upc;
		up4 = upd;
		price1 = pricea;
		price2 = priceb;
		price3 = pricec;
		price4 = priced;
		backGround = &back;
		drawables.push_back(backGround);
		dayT = &day;
		drawables.push_back(dayT);
		message = prompt;
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
		drawables.push_back(player);

	}

	bool update(sf::RenderWindow &window, bool &winner) {
		sf::Text result;
		result.setFont(font);
		result.setPosition(400, 400);

		bool isEnd = true;
		bool isShop = true;
		while (isShop) {
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Num1) {
						if (player->getMoney() >= price1 && player->getPower() + up1 <= 10) {
							player->setMoney(player->getMoney() - price1);
							player->setPower(player->getPower() + up1);
						}
						if (player->getPower() + up1 > 10) {
							player->setPower(10);
						}
					}
					else if (event.key.code == sf::Keyboard::Num2) {
						if (player->getMoney() >= price2 && player->getSpeed() + up2 <= 90) {
							player->setMoney(player->getMoney() - price2);
							player->setSpeed(player->getSpeed() + up2);
						}
						if (player->getSpeed() + up2 > 90) {
							player->setSpeed(90);
						}
					}
					else if (event.key.code == sf::Keyboard::Num3) {
						if (player->getMoney() >= price3 && player->getHealth() + up3 <= player->getHealthMax()) {
							player->setMoney(player->getMoney() - price3);
							player->setHealth(player->getHealth() + up3);
						}
						if (player->getHealth() > player->getHealthMax()) {
							player->setHealth(player->getHealthMax());
						}
					}
					else if (event.key.code == sf::Keyboard::Num4) {
						if (player->getMoney() >= price4) {
							player->setMoney(player->getMoney() - price4);
							player->setHealth(player->getHealth() + up4);
							player->setHealthMax(player->getHealthMax() + up4);
						}
					}
					else if (event.key.code == sf::Keyboard::Return) {
						isShop = false;
					}
				}
			}
			window.clear();
			updateStat(*player);
			window.draw(*this);
			window.display();
		}
		while (isEnd) {
			sf::Event eventE;
			while (window.pollEvent(eventE))
			{
				if (isEnd) {
					result.setString("Thanks for shopping!");
					if (eventE.type == sf::Event::KeyPressed) {
						if (eventE.key.code == sf::Keyboard::Return) {
							isEnd = false;
							//window.draw(result);
						}
					}
				}
			}
			window.clear();
			updateStat(*player);
			window.draw(*this);
			window.draw(result);
			window.display();
			//window.clear();
		}
		//return false;
		//}
		//return true;
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

	bool update() {
		update();
		return true;
	}

};
