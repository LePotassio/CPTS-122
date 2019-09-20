#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


using std::string;
class person {
private:
	string name;
	int health;
public:
	person(string newName, int healthStart);
	person();
	~person();

	string getName();
	void setName(string newName);

	int getHealth();
	void setHealth(int newHealth);
	void addORsubHealth(int addAmount);

};