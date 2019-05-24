#pragma once
#include "State.h"
#include "Grid.h"

class GameState : public State
{
public:
	GameState(sf::RenderWindow *window, std::map<std::string, unsigned int>* inputKeys, std::stack<State*> *states);
	virtual ~GameState();

	void UpdateInput(const float dt = 0);
	void Update(const float dt);
	void Draw(sf::RenderWindow *window = nullptr);

private:
	void InitFrame(const unsigned int windowWidth, const unsigned int windowHeight);
	void InitGrid(const float frameWidth, const float frameHeight);
	void InitKeyBinds();
	sf::RectangleShape mFrame;
	Grid *pGrid = nullptr;
};

