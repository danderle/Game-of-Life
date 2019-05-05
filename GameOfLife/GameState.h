#pragma once
#include "State.h"

class GameState : public State
{
public:
	GameState(sf::RenderWindow *window);
	virtual ~GameState();

	void EndState();
	void UpdateKeybinds(const float dt = 0);
	void Update(const float dt);
	void Draw(sf::RenderTarget *target = nullptr);
};

