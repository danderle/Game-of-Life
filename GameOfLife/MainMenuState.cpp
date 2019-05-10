#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow * window, std::map<std::string, unsigned int>* inputKeys)
	:
	State(window, inputKeys)
{
	InitKeyBinds();
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::EndState()
{
}

void MainMenuState::UpdateInput(const float dt)
{
	CheckForQuit();
}

void MainMenuState::Update(const float dt)
{
}

void MainMenuState::Draw(sf::RenderWindow * window)
{
	if (!window)
		window = pWindow;
	window->clear(sf::Color::Magenta);
}

void MainMenuState::InitFrame(const unsigned int windowWidth, const unsigned int windowHeight)
{
}

void MainMenuState::InitKeyBinds()
{
}
