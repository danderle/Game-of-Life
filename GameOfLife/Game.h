#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"

class Game
{
public:
	Game() = delete;
	Game(const unsigned int windowWidth, const unsigned int windowHeight, const std::string &windowTitle);
	~Game();

	void Loop();


private:
	sf::RenderWindow *pWindow;
	sf::RectangleShape mRect;

	Grid *pGrid;
};

