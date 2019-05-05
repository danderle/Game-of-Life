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

void GameState::Update(const float dt)
{
}

void GameState::Draw(sf::RenderTarget * target)
{
}