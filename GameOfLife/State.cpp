#include "State.h"


State::State(sf::RenderWindow * window, std::map<std::string, unsigned int>* inputKeys)
	:
	pWindow(window),
	maInputKeys(inputKeys),
	mQuit(false)
{
}

State::~State()
{
}

void State::UpdateMousePosition()
{
	mMousePosScreen = sf::Mouse::getPosition();
	mMousePosWindow = sf::Mouse::getPosition(*pWindow);
	mMousePosView = pWindow->mapPixelToCoords(sf::Mouse::getPosition(*pWindow));
}

void State::CheckForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(maKeyBinds.at("Quit"))))
		mQuit = true;
}

const bool State::GetQuit() const
{
	return mQuit;
}
