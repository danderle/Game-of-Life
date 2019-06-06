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
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned int textSize,
		sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
		sf::Color buttonIdleColor, sf::Color buttonHoverColor, sf::Color buttonActiveColor);
	virtual ~Button();

	void Draw(sf::RenderWindow* window);
	void Update(const sf::Vector2f mousePos);
	const bool IsPressed() const;

private:
	enum ButtonStates mButtonState;

	sf::RectangleShape mShape;
	sf::Font *pFont;

	sf::Text mText;
	sf::Color mTextIdleColor;
	sf::Color mTextHoverColor;
	sf::Color mTextActiveColor;

	sf::Color mButtonIdleColor;
	sf::Color mButtonHoverColor;
	sf::Color mButtonActiveColor;
};

