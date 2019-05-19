#pragma once

#include <SFML/Graphics.hpp>

enum ButtonStates
{
	BTN_IDLE = 0,
	BTN_HOVER = 1,
	BTN_ACTIVE = 2
};

class Button
{
public:
	Button() = delete;
	Button(float x, float y, float width, float height, sf::Font* font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	virtual ~Button();

	void Draw(sf::RenderWindow* window);
	void Update(const sf::Vector2f mousePos);
	const bool IsPressed() const;

private:
	enum ButtonStates mButtonState;

	sf::RectangleShape mShape;
	sf::Font *pFont;
	sf::Text mText;
	sf::Color mIdleColor;
	sf::Color mHoverColor;
	sf::Color mActiveColor;
};

