#pragma once

#include <SFML/Graphics.hpp>

class button : public sf::Drawable {

private:
	
protected:
	sf::Text *text;
	sf::Font font;
	sf::RectangleShape *butt;
public:
	button(std::string textS) {
		font.loadFromFile("arial.ttf");
		text = new sf::Text();
		text->setString(textS);
		text->setFont(font);
		text->setFillColor(sf::Color::Cyan);
		butt = new sf::RectangleShape(sf::Vector2f(200, 50));
	}
	~button() {
		delete text;
		delete butt;
	}
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
		target.draw(*butt, states);
		target.draw(*text, states);
	}
	virtual void setPosition(float x, float y) {
		(*text).setPosition(x, y);
		(*butt).setPosition(x, y);
	}
	virtual void setScale(float sizex, float sizey) {
		(*text).setScale(sizex, sizey);
		(*butt).setScale(sizex, sizey);
	}
};