#pragma once
#include "Grid.h"
#include "State.h"

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
	void Render();
	void Run();


private:
	//Variables
	sf::RenderWindow *pWindow;
	sf::RectangleShape mFrame;
	sf::Event sfEvent;
	sf::Clock sfClock;

	float dt;
	Grid *pGrid;

	//Initializers
	void InitWindow();
	void InitFrame(const unsigned int windowWidth, const unsigned int windowHeight);
	void InitGrid(const float frameWidth, const float frameHeight);
};

