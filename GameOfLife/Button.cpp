#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font * font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
	:
	mButtonState(BTN_IDLE),
	pFont(font),
	mIdleColor(idleColor),
	mHoverColor(hoverColor),
	mActiveColor(activeColor)
{
	mShape.setSize(sf::Vector2f(width, height));
	mShape.setPosition(sf::Vector2f(x, y));
	
	mText.setFont(*pFont);
	mText.setString(text);
	mText.setFillColor(sf::Color::Black);
	mText.setCharacterSize(20);
	mText.setPosition(mShape.getPosition().x + (mShape.getGlobalBounds().width/2.f) - mText.getGlobalBounds().width/2.f,
		mShape.getPosition().y + (mShape.getGlobalBounds().height/2.f)  - mText.getGlobalBounds().height/2.f);

	mShape.setFillColor(mIdleColor);
}


Button::~Button()
{
}

void Button::Draw(sf::RenderWindow * window)
{
	window->draw(mShape);
	window->draw(mText);
}

void Button::Update(const sf::Vector2f mousePos)
{
	//Button is idle
	mButtonState = BTN_IDLE;

	//Button is hovered
	if (mShape.getGlobalBounds().contains(mousePos))
	{
		mButtonState = BTN_HOVER;

		//Button is pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			mButtonState = BTN_ACTIVE;
		}
	}

	switch (mButtonState)
	{
	case BTN_IDLE:
		mShape.setFillColor(mIdleColor);
		break;
	case BTN_HOVER:
		mShape.setFillColor(mHoverColor);
		break;
	case BTN_ACTIVE:
		mShape.setFillColor(mActiveColor);
		break;
	default:
		mShape.setFillColor(sf::Color::Red);
	}
}
const bool Button::IsPressed() const
{
	return mButtonState == BTN_ACTIVE;
}


