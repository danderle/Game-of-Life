#pragma once

#include <SFML/Graphics.hpp>

class Button
{
public:
	Button() = delete;
	Button(float x, float y, float width, float height, sf::Font* font, std::string &text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	virtual ~Button();

	void Draw(sf::RenderWindow* window);
	void Update(const sf::Vector2f mousePos);

private:
	sf::RectangleShape mShape;
	sf::Font *pFont;
	sf::Text mText;
	sf::Color mIdleColor;
	sf::Color mHoverColor;
	sf::Color mActiveColor;
};

