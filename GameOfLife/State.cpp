#include "State.h"


State::State(sf::RenderWindow * window, std::map<std::string, unsigned int>* inputKeys, std::stack<State*> *states)
	:
	pWindow(window),
	maInputKeys(inputKeys),
	mQuit(false),
	sStates(states)
{
}

State::~State()
{
}

void State::EndState()
{
	mQuit = true;
}

void State::UpdateMousePosition()
{
	mMousePosScreen = sf::Mouse::getPosition();
	mMousePosWindow = sf::Mouse::getPosition(*pWindow);
	mMousePosView = pWindow->mapPixelToCoords(sf::Mouse::getPosition(*pWindow));
}

const bool State::GetQuit() const
{
	return mQuit;
}
