#include "State.h"


State::State(sf::RenderWindow * window)
	:
	pWindow(window),
	mQuit(false)
{
}

State::~State()
{
}

void State::CheckForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		mQuit = true;
}

const bool State::GetQuit() const
{
	return mQuit;
}
