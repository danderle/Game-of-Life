#pragma once
#include "State.h"
#include "Grid.h"

class GameState : public State
{
public:
	GameState(sf::RenderWindow *window);
	virtual ~GameState();

	void EndState();
	void UpdateInput(const float dt = 0);
	void Update(const float dt);
	void Draw(sf::RenderWindow *window = nullptr);

private:
	void InitFrame(const unsigned int windowWidth, const unsigned int windowHeight);
	void InitGrid(const float frameWidth, const float frameHeight);

	sf::RectangleShape mFrame;
	Grid *pGrid = nullptr;
};

