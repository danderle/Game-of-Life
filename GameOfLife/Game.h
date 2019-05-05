#pragma once
#include "Grid.h"
#include "GameState.h"

class Game
{
public:
	//Constructors and destructor
	Game();
	virtual ~Game();

	//Methods
	void UpdateDt();
	void UpdateSFMLEvents();
	void Update();
	void Draw();
	void Run();


private:
	//Variables
	sf::RenderWindow *pWindow;
	sf::RectangleShape mFrame;
	sf::Event sfEvent;
	sf::Clock sfClock;

	float mDt;
	Grid *pGrid;
	std::stack<State*> sStates;

	//Initializers
	void InitWindow();
	void InitStates();
	void InitFrame(const unsigned int windowWidth, const unsigned int windowHeight);
	void InitGrid(const float frameWidth, const float frameHeight);
};

