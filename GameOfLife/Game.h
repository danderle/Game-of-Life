#pragma once
#include "Grid.h"
#include "GameState.h"
#include "MainMenuState.h"

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
	sf::Event sfEvent;
	sf::Clock sfClock;

	float mDt;
	std::stack<State*> sStates;
	std::map<std::string, unsigned int> maInputKeys;

	//Initializers
	void InitWindow();
	void InitInputKeys();
	void InitStates();
};

