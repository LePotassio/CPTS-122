#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <vector>

//#include "statChange.h"
#include "battleHappen.h"
#include "shopHappen.h"
/*
FIX:
Mouse move to advance last enter
*/

void newDay(int &day, sf::Text &Day);
std::vector<happen *> loadHappenings(ship &player, sf::Text &status, sf::Sprite &background, sf::Text &day);
std::vector<happen *> loadHappenings2(ship &player, sf::Text &status, sf::Sprite &background, sf::Text &day);
std::vector<happen *> loadHappenings3(ship &player, sf::Text &status, sf::Sprite &background, sf::Text &day);
std::vector<happen *> loadHappeningsBosses(ship &player, sf::Text &status, sf::Sprite &backround, sf::Text &day);
bool updateStat(ship &player, sf::Text &status);
int main()
{
	//
	int per1End = 50;
	int per2End = 100;
	int per3End = 150;
	//

	srand((unsigned int) time(NULL));

	sf::RenderWindow window(sf::VideoMode(1100, 700), "Sea of S");
	happen * whatHappened = nullptr;

	sf::String input;
	sf::Text text;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	text.setFont(font);

	text.setPosition(350,50);
	text.setFillColor(sf::Color::Cyan);
	sf::Text test;
	test.setFont(font);
	test.setString("Plox Enter Your Ship Name\n\n\n\nStats Have Been Adjusted to Easyish Demo\nControls:\nAdvance: Enter (Hit this alot)\nShop Selection: Numbers 1-5\nHow To Play: Survive 150 Days on the Sea of S\n Stats:\n-Power - >Amount of dmg per shot(Max 10)\n-Speed - > Percent chance of dodging a shot(Max 90)\n-Health -> Don't let this hit 0\n-Max Health -> Maximum amount of health\nthe ship can have");
	test.setPosition(100, 10);

	sf::Texture shipTexture;
	shipTexture.loadFromFile("canoe.png");
	ship player;
	player.setTexture(shipTexture);
	player.setPower(1);
	player.setSpeed(10);
	player.setHealth(20);
	player.setHealthMax(20);
	player.setScale(.25, .25);
	player.setPosition(150, 450);
	

	bool exitMenu = false;

	sf::Text shipNamer;
	shipNamer.setFont(font);
	shipNamer.setPosition(200,600);
	///////////////////////////////////////////////////////////////////


	sf::Text Money;
	
	sf::Text crew1;
	player.addCrew("Cpt Andrew O'Fallon");
	std::string crew1P;
	crew1P += "Name: ";
	crew1P += player.getCrew()[0].getName();
	std::stringstream conv;
	conv << player.getCrew()[0].getHealth();
	crew1P += "\nHealth: ";
	crew1P += conv.str();
	crew1.setFont(font);
	crew1.setString(crew1P);
	crew1.setPosition(0, 0);
	crew1.setCharacterSize(22);
	
	std::string MoneyP;
	MoneyP += "Money: ";
	std::stringstream MoneyC;
	MoneyC << player.getMoney();
	MoneyP += MoneyC.str();
	Money.setFont(font);
	Money.setString(MoneyP);
	Money.setPosition(0, 200);
	Money.setCharacterSize(22);

	sf::Text Day;
	int day = 0;
	std::string DayP;
	DayP += "Day: ";
	std::stringstream DayC;
	DayC << day;
	DayP += DayC.str();
	Day.setFont(font);
	Day.setString(DayP);
	Day.setPosition(0, 300);
	Day.setCharacterSize(22);

	button butt1("Accept");
	butt1.setPosition(500, 500);

	button butt2("Decline");
	butt2.setPosition(500, 600);

	button butt3("Fire All");
	butt3.setPosition(750, 500);

	button butt4("Sudoku");
	butt4.setPosition(750, 600);

	bool isPause = false;
	bool showButtons = false;
	int happenN = 0;

	sf::Texture back;
	back.loadFromFile("ocean.png");
	sf::Sprite background;
	background.setTexture(back);
	background.setPosition(0, -100);

	//statChange *statChanger = nullptr;
	//sf::Texture eTexture;
	//std::stringstream intToString;

	sf::Text status("", font, 22);

	bool isHappenDone = true;
	std::vector<happen *>happens = loadHappenings(player, status, background, Day);
	bool winner;
	bool gameOver = false;
	sf::Text rip;
	rip.setFont(font);
	rip.setPosition(300, 300);
	rip.setScale(3, 3);
	rip.setString("You Lose\nClose Window and rerun\nto restart");

	std::vector<happen *>happens2 = loadHappenings2(player, status, background, Day);
	std::vector<happen *>happens3 = loadHappenings3(player, status, background, Day);
	std::vector<happen *>happensBosses = loadHappeningsBosses(player, status, background, Day);
	//
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();

			window.clear(sf::Color::Black);

			if (exitMenu == false) {
				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Return) {
						exitMenu = true;
						player.setName(input);
						shipNamer.setString(input);
					}
				}
				if (event.type == sf::Event::TextEntered) {
					input += /*static_cast<char>*/(event.text.unicode);
					text.setString(input);
				}
			}
			else {
				if (day < per1End - 1 && player.getHealth() >= 1) {//end of game cond
					if (isHappenDone) {
						happenN = rand() % happens.size();
					}
					if (isPause == false) {
						newDay(day, Day);
						isHappenDone = happens[happenN]->update(window, winner);
						whatHappened = happens[happenN];
						isPause = true;
						updateStat(player, status);
					}

					if (event.type == sf::Event::KeyPressed) {
						if (event.key.code == sf::Keyboard::Return) {
							isPause = false;
						}
					}
					/////////////////////////////////////////////////////////////////////////////
				}
				else if ((day == per1End || day == per1End - 1) && player.getHealth() >= 1) {
					if (day == per1End) {
						if (isPause == false) {
							newDay(day, Day);
							isHappenDone = happensBosses[0]->update(window, winner);
							whatHappened = happensBosses[0];
							isPause = true;
							updateStat(player, status);
						}

						if (event.type == sf::Event::KeyPressed) {
							if (event.key.code == sf::Keyboard::Return) {
								isPause = false;
							}
						}
					}
					else {
						if (isPause == false) {
							newDay(day, Day);
							isHappenDone = happensBosses[1]->update(window, winner);
							whatHappened = happensBosses[1];
							isPause = true;
							updateStat(player, status);
						}

						if (event.type == sf::Event::KeyPressed) {
							if (event.key.code == sf::Keyboard::Return) {
								isPause = false;
							}
						}
					}
				}
				else if (day < per2End - 1 && player.getHealth() >= 1) {
					if (isHappenDone) {
						happenN = rand() % happens2.size();
					}
					if (isPause == false) {
						newDay(day, Day);
						isHappenDone = happens2[happenN]->update(window, winner);
						whatHappened = happens2[happenN];
						isPause = true;
						updateStat(player, status);
					}

					if (event.type == sf::Event::KeyPressed) {
						if (event.key.code == sf::Keyboard::Return) {
							isPause = false;
						}
					}
				}
				else if ((day == per2End || day == per2End - 1) && player.getHealth() >= 1) {
					if (day == per2End) {
						if (isPause == false) {
							newDay(day, Day);
							isHappenDone = happensBosses[0]->update(window, winner);
							whatHappened = happensBosses[0];
							isPause = true;
							updateStat(player, status);
						}

						if (event.type == sf::Event::KeyPressed) {
							if (event.key.code == sf::Keyboard::Return) {
								isPause = false;
							}
						}
					}
					else {
						if (isPause == false) {
							newDay(day, Day);
							isHappenDone = happensBosses[2]->update(window, winner);
							whatHappened = happensBosses[2];
							isPause = true;
							updateStat(player, status);
						}

						if (event.type == sf::Event::KeyPressed) {
							if (event.key.code == sf::Keyboard::Return) {
								isPause = false;
							}
						}
					}
				}
				else if (day < per3End - 1 && player.getHealth() >= 1) {
					if (isHappenDone) {
						happenN = rand() % happens3.size();
					}
					if (isPause == false) {
						newDay(day, Day);
						isHappenDone = happens3[happenN]->update(window, winner);
						whatHappened = happens3[happenN];
						isPause = true;
						updateStat(player, status);
					}

					if (event.type == sf::Event::KeyPressed) {
						if (event.key.code == sf::Keyboard::Return) {
							isPause = false;
						}
					}
				}
				else if ((day == per3End || day == per3End - 1) && player.getHealth() >= 1) {
					if (day == per3End) {
						if (isPause == false) {
							newDay(day, Day);
							isHappenDone = happensBosses[0]->update(window, winner);
							whatHappened = happensBosses[0];
							isPause = true;
							updateStat(player, status);
						}

						if (event.type == sf::Event::KeyPressed) {
							if (event.key.code == sf::Keyboard::Return) {
								isPause = false;
							}
						}
					}
					else {
						if (isPause == false) {
							newDay(day, Day);
							isHappenDone = happensBosses[3]->update(window, winner);
							whatHappened = happensBosses[3];
							isPause = true;
							updateStat(player, status);
						}

						if (event.type == sf::Event::KeyPressed) {
							if (event.key.code == sf::Keyboard::Return) {
								isPause = false;
							}
						}
					}
				}
				else {
					//end of game stuff
					if (player.getHealth() < 1) {
						//lose
						gameOver = true;
					}
					else {
						//win
						rip.setString("You Win! Nerd");
						gameOver = true;
					}
				}
				
			}
		}
		if (gameOver == false) {
			window.clear();
			if (exitMenu == false) {
				window.draw(test);
				window.draw(text);
			}
			else {
				window.draw(background);
				window.draw(player);
				window.draw(shipNamer);
				//window.draw(crew1);
				//window.draw(Money);
				if (whatHappened != nullptr)
					window.draw(*whatHappened);
				//whatHappened = nullptr;
				//window.draw(butt1);
				//window.draw(butt2);
				//window.draw(butt3);
				//window.draw(butt4);
				window.draw(Day);
				window.draw(status);

			}
		}
		else {
			window.draw(rip);
			window.draw(Day);
		}

		window.display();
	}

	return 0;
}

std::vector<happen *> loadHappenings(ship &player, sf::Text &status, sf::Sprite &backround, sf::Text &day) {
	sf::Texture enemyShip;
	enemyShip.loadFromFile("smallShip.png");
	std::vector<happen *> happenings;

	//Stat Changes
	happenings.push_back(new statChange(money,300, &player, "The Apache Helicopter of fortune\nshines upon you today (+300 Gold)", "gold.png"));
	happenings.push_back(new statChange(health, 2, &player, "An old dude agrees to help\nyou and repairs your\nship by 2hp !", "oldDude.png"));
	happenings.push_back(new statChange(money, 250, &player, "The Waters here are ripe with\nvalueable fishies,\ncatching a few in the morning (+250 gold)", "fishies.png"));
	//happenings.push_back(new statChange(money, -200, &player, "Your Money Blew Up  (-200 gold)", "goldL.png"));
	
	//Ship Battles - > could implement customizable backgrounds
	happenings.push_back(new battleHappen(&player, "Now Battling Ghetto Ship", "smallShip.png", new ship("ShipE", 1, 10, 2, enemyShip), status, backround, day, 150));
	happenings.push_back(new battleHappen(&player, "Now Battling Supa Sonic Jet Skert", "fastShip.png", new ship("ShipE", 1, 40, 3, enemyShip), status, backround, day, 300));
	happenings.push_back(new battleHappen(&player, "Now Battling Fisher X", "fisher.png", new ship("ShipE", 1, 20, 2, enemyShip), status, backround, day, 200));
	happenings.push_back(new battleHappen(&player, "Now Battling Chugga Chugga\nDeath Spa", "hottub.png", new ship("ShipE", 2, 10, 1, enemyShip), status, backround, day, 100));
	happenings.push_back(new battleHappen(&player, "Now Battling: The Titanic", "titanic.png", new ship("ShipE", 0, 0, 1, enemyShip), status, backround, day, 100));

	//Shop Happens (can make customizable later)
	happenings.push_back(new shopHappen(&player, "Billy Mayes here for ship upgrades.\n(1) +1 power -> 1000\n(2) +10 speed -> 500\n(3) heal 1hp -> 20\n(4) +5 max health -> 1000\n(Enter) Leave\n", "shopkeeper.png", status, backround, day, 1000, 500, 20, 1000, 1, 10, 1, 5));
	happenings.push_back(new shopHappen(&player, "Billy Mayes here for ship upgrades.\n(1) +1 power -> 1000\n(2) +10 speed -> 500\n(3) heal 1hp -> 20\n(4) +5 max health -> 1000\n(Enter) Leave\n", "shopkeeper.png", status, backround, day, 1000, 500, 20, 1000, 1, 10, 1, 5));
	happenings.push_back(new shopHappen(&player, "The Sea can be tough if\nYa don't got Health\n(3) heal 1hp -> 20\n(Enter) Leave\n", "healDude.png", status, backround, day, 999999, 999999, 20, 999999, 0, 0, 1, 0));//this was originaly supposed to be passages malibu

	return happenings;
}

std::vector<happen *> loadHappenings2(ship &player, sf::Text &status, sf::Sprite &backround, sf::Text &day) {
	sf::Texture enemyShip;
	enemyShip.loadFromFile("smallShip.png");
	std::vector<happen *> happenings;

	//Stat Changes
	happenings.push_back(new statChange(money, 300, &player, "The Apache Helicopter of fortune\nshines upon you today (+300 Gold)", "gold.png"));
	happenings.push_back(new statChange(money, 0, &player, "An old friend gives you his\n antique cereal collection (+10 Box Tops)", "royalCapt.png"));
	happenings.push_back(new statChange(health, 2, &player, "An old dude agrees to help\nyou and repairs your\nship by 2hp !", "oldDude.png"));
	happenings.push_back(new statChange(money, -200, &player, "Your Money Blew Up  (-200 gold)", "goldL.png"));
	happenings.push_back(new statChange(money, 10, &player, "Your Ghost Dad Scolds You then gives\n mothly allowance  (-1 dignity) (+10 gold)", "dadNOO.png"));
	happenings.push_back(new statChange(money, 200, &player, "You Recover Davey Jones' launcher (+200 gold)", "launcher.png"));
	happenings.push_back(new statChange(money, 400, &player, "You spot a rock lobster\nThe luck of the sea must be\nin your favor (+400 gold)", "rockLobster.png"));
	//happenings.push_back(new statChange(power, 1, &player, "Seasoned Weapon Expert (SWE)\nupgrades your power by 1 !", "weaponExpert.png"));

	//Ship Battles - > could implement customizable backgrounds
	//happenings.push_back(new battleHappen(&player, "Now Battling: Ghetto Ship", "smallShip.png", new ship("ShipE", 1, 10, 2, enemyShip), status, backround, day, 200));
	happenings.push_back(new battleHappen(&player, "Now Battling: Disney Family Adventurer", "bigShip.png", new ship("ShipE", 4, 20, 18, enemyShip), status, backround, day, 700));
	//happenings.push_back(new battleHappen(&player, "Now Battling: Supa Sonic", "fastShip.png", new ship("ShipE", 1, 40, 3, enemyShip), status, backround, day, 400));
	happenings.push_back(new battleHappen(&player, "Now Battling: Commies", "commieSub.png", new ship("ShipE", 3, 65, 7, enemyShip), status, backround, day, 350));
	happenings.push_back(new battleHappen(&player, "Now Battling: Weebs", "weebs.png", new ship("ShipE", 4, 30, 12, enemyShip), status, backround, day, 400));
	happenings.push_back(new battleHappen(&player, "Now Battling: A Dank Engine", "dankEngine.png", new ship("ShipE", 2, 50, 15, enemyShip), status, backround, day, 400));
	happenings.push_back(new battleHappen(&player, "Now Battling: Moby Dick", "mobyDick.png", new ship("ShipE", 3, 20, 12, enemyShip), status, backround, day, 500));
	happenings.push_back(new battleHappen(&player, "Now Battling: The Matrimony of\nBob and Cameron", "wedding.png", new ship("ShipE", 0, 10, 5, enemyShip), status, backround, day, 100));
	happenings.push_back(new battleHappen(&player, "Now Battling: The Cracken", "kraken.png", new ship("ShipE", 4, 0, 25, enemyShip), status, backround, day, 700));
	happenings.push_back(new battleHappen(&player, "Now Battling: A Ship of CPTS 121 Students", "cpts121.png", new ship("ShipE", 0, 0, 2, enemyShip), status, backround, day, 100));


	//Shop Happens (can make customizable later)
	happenings.push_back(new shopHappen(&player, "Billy Mayes here for ship upgrades.\n(1) +1 power -> 1000\n(2) +10 speed -> 500\n(3) heal 1hp -> 20\n(4) +5 max health -> 1000\n(Enter) Leave\n", "shopkeeper.png", status, backround, day, 1000, 500, 20, 1000, 1, 10, 1, 5));
	happenings.push_back(new shopHappen(&player, "Billy Mayes here for ship upgrades.\n(1) +1 power -> 1000\n(2) +10 speed -> 500\n(3) heal 1hp -> 20\n(4) +5 max health -> 1000\n(Enter) Leave\n", "shopkeeper.png", status, backround, day, 1000, 500, 20, 1000, 1, 10, 1, 5));
	happenings.push_back(new shopHappen(&player, "I got lower prices than Billy\n(1) +1 power -> 1200\n(2) +10 speed -> 600\n(3) heal 1hp -> 20\n(4) +5 max health -> 2000\n(Enter) Leave\n", "shopkeeperPLEB.png", status, backround, day, 1200, 600, 20, 2000, 1, 10, 1, 5));
	happenings.push_back(new shopHappen(&player, "Buying in bulk can save\n -Mom\n(1) +5 power -> 4000\n(2) +50 speed -> 2000\n(3) heal 5hp -> 80\n(4) +25 max health -> 4000\n(Enter) Leave\n", "costco.png", status, backround, day, 4000, 2000, 80, 4000, 5, 50, 5, 25));
	//happenings.push_back(new shopHappen(&player, "I'll Heal Ya\nIf Ya Pay\nIf ya Like\n(3) heal 1hp -> 100\n(Enter) Leave\n", "healDude.png", status, backround, day, 999999, 999999, 100, 999999, 0, 0, 1, 0));//this was originaly supposed to be passages malibu


	return happenings;
}

std::vector<happen *> loadHappenings3(ship &player, sf::Text &status, sf::Sprite &backround, sf::Text &day) {
	sf::Texture enemyShip;
	enemyShip.loadFromFile("smallShip.png");
	std::vector<happen *> happenings;

	//Stat Changes
	happenings.push_back(new statChange(money, 300, &player, "The Apache Helicopter of fortune\nshines upon you today (+300 Gold)", "gold.png"));
	happenings.push_back(new statChange(health, 2, &player, "An old dude agrees to help\nyou and repairs your\nship by 2hp !", "oldDude.png"));
	happenings.push_back(new statChange(health, -1, &player, "Lack of food leads to food hallucinations\n(-1 Health)", "foood.png"));
	happenings.push_back(new statChange(health, 1, &player, "The sea is calm today\nallowing you and your crew\nto reflect on their past\n(+1 Health)", "calm.png"));
	happenings.push_back(new statChange(maxHealth, 5, &player, "Ocean Man take me by the hand\nlead me to the land that you understand\n(+5 Max Health)", "oceanMan.png"));
	happenings.push_back(new statChange(health, 5, &player, "A crew member spots KFC Island\nover the starboard\n(+10 Health)", "kfcIsland.png"));
	
	happenings.push_back(new battleHappen(&player, "Now Battling: Vikings", "vikings.png", new ship("ShipE", 4, 30, 40, enemyShip), status, backround, day, 900));
	happenings.push_back(new battleHappen(&player, "Now Battling: Space Titanic", "spaceTitanic.png", new ship("ShipE", 5, 0, 65, enemyShip), status, backround, day, 1100));
	happenings.push_back(new battleHappen(&player, "Now Battling: Pirates", "pirates.png", new ship("ShipE", 5, 70, 25, enemyShip), status, backround, day, 800));
	happenings.push_back(new battleHappen(&player, "Now Battling: Sharkano Island", "sharkano.png", new ship("ShipE", 3, 0, 80, enemyShip), status, backround, day, 1000));
	happenings.push_back(new battleHappen(&player, "Now Battling: The Bermuda Triangle", "triangle.png", new ship("ShipE", 4, 80, 20, enemyShip), status, backround, day, 1000));

	happenings.push_back(new shopHappen(&player, "Billy Mayes here for ship upgrades.\n(1) +1 power -> 1000\n(2) +10 speed -> 500\n(3) heal 1hp -> 20\n(4) +5 max health -> 1000\n(Enter) Leave\n", "shopkeeper.png", status, backround, day, 1000, 500, 20, 1000, 1, 10, 1, 5));
	happenings.push_back(new shopHappen(&player, "Billy Mayes here for ship upgrades.\n(1) +1 power -> 1000\n(2) +10 speed -> 500\n(3) heal 1hp -> 20\n(4) +5 max health -> 1000\n(Enter) Leave\n", "shopkeeper.png", status, backround, day, 1000, 500, 20, 1000, 1, 10, 1, 5));
	happenings.push_back(new shopHappen(&player, "Buying in bulk can save\n -Mom\n(1) +5 power -> 4000\n(2) +50 speed -> 2000\n(3) heal 5hp -> 80\n(4) +25 max health -> 4000\n(Enter) Leave\n", "costco.png", status, backround, day, 4000, 2000, 80, 4000, 5, 50, 5, 25));
	happenings.push_back(new shopHappen(&player, "I'm Rick Harrison, and this is my ship shop.\n(1) +1 power -> 800\n(2) +10 speed -> 300\n(3) heal 1hp -> 10\n(4) +5 max health -> 800\n(Enter) Leave\n", "rick.png", status, backround, day, 800, 300, 10, 800, 1, 10, 1, 5));
	happenings.push_back(new shopHappen(&player, "This time on Shark Tank...We Want Speed...\n(2) +10 speed -> 250\n(Enter) Leave\n", "sharkTank.png", status, backround, day, 999999, 250, 999999, 999999, 0, 10, 0, 0));
	//happenings.push_back(new shopHappen(&player, "I'll Heal Ya\nIf Ya Pay\nIf ya Like\n(3) heal 1hp -> 100\n(Enter) Leave\n", "healDude.png", status, backround, day, 999999, 999999, 100, 999999, 0, 0, 1, 0));//this was originaly supposed to be passages malibu


	return happenings;
}

std::vector<happen *> loadHappeningsBosses(ship &player, sf::Text &status, sf::Sprite &backround, sf::Text &day) {
	sf::Texture enemyShip;
	enemyShip.loadFromFile("smallShip.png");
	std::vector<happen *> happenings;

	//Ship Battles - > could implement customizable backgrounds
	happenings.push_back(new statChange(health, player.getHealthMax(), &player, "After fighting a boss\ndude repairs your ship fully !", "wiseOldDude.png"));
	happenings.push_back(new battleHappen(&player, "Now Battling Boss: Truck Freak\nThe Amphibious Nightmare", "truckFreak.png", new ship("ShipE", 4, 0, 20, enemyShip), status, backround, day, 2000));
	happenings.push_back(new battleHappen(&player, "Now Battling Boss: Crazy Ass\nThe Terror of The Sea", "crazyAss.png", new ship("ShipE", 8, 20, 50, enemyShip), status, backround, day, 4000));
	happenings.push_back(new battleHappen(&player, "Now Battling Boss: The Fighter\nSuplexer of Worlds", "theFighter.png", new ship("ShipE", 15, 25, 150, enemyShip), status, backround, day, 0));

	return happenings;
}

void newDay(int &day, sf::Text &Day) {
	day++;
	std::string DayP;
	DayP += "Day: ";
	std::stringstream DayC;
	DayC << day;
	DayP += DayC.str();
	Day.setString(DayP);
}

bool updateStat(ship &player, sf::Text &status) {
	//std::cout << "before money : " << player.getMoney() << std::endl;
	std::stringstream stats;
	//std::cout << "after money : " << player.getMoney() << std::endl;
	//std::cout << "Player memory location : " << &player << std::endl;
	stats << "Money:\n" << player.getMoney() << "\nHealth:\n" << player.getHealth() << "/" << player.getHealthMax() << "\nSpeed:\n" << player.getSpeed() << "\nPower:\n" << player.getPower() << "\n\0";
	string temp = stats.str();
	status.setString(temp);

	//TODO: do the stuff that this even should do,each time update is called you should progress one step and return true when done with the entire event

	return true;
}