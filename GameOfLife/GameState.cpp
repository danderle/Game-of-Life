#include "GameState.h"


GameState::GameState(sf::RenderWindow *window)
	:
	State(window)
{
}


GameState::~GameState()
{
}

void GameState::EndState()
{
}

void GameState::UpdateKeybinds(const float dt)
{
	CheckForQuit();
}

void GameState::Update(const float dt)
{
	UpdateKeybinds(dt);
}

void GameState::Draw(sf::RenderTarget * target)
{
}