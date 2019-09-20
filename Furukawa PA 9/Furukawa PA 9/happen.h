#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "button.h"
#include "ship.h"

class happen : public sf::Drawable {
private:
	
protected:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
		for (sf::Drawable *itr : drawables) {
			target.draw(*itr, states);
		}
	}

	std::vector<sf::Drawable *> drawables;
public:
	happen() {

	}

	~happen() {
		for (sf::Drawable *itr : drawables) {
			delete itr;
		}
	}
	virtual bool update(sf::RenderWindow &window, bool &winner) = 0;
};