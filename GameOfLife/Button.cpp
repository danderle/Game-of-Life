#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font * font, std::string & text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
	:
	pFont(font),
	mIdleColor(idleColor),
	mHoverColor(hoverColor),
	mActiveColor(activeColor)
{
	mShape.setSize(sf::Vector2f(width, height));
	mShape.setPosition(sf::Vector2f(x, y));
	
	mText.setFont(*pFont);
	mText.setString(text);
	mText.setFillColor(sf::Color::White);
	mText.setCharacterSize(12);
	mText.setPosition(mShape.getPosition().x/2.f - mText.getGlobalBounds().width/2.f,
		mShape.getPosition().y - mText.getGlobalBounds().height/2.f);

	mShape.setFillColor(mIdleColor);
}


Button::~Button()
{
}

void Button::Draw(sf::RenderWindow * window)
{
	window->draw(mShape);
}

void Button::Update(const sf::Vector2f mousePos)
{
	if (mShape.getGlobalBounds().contains(mousePos))
		//do something
		;
}
