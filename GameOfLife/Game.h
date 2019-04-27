#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game() = delete;
	Game(const unsigned int windowWidth, const unsigned int windowHeight, const std::string &windowTitle);
	~Game();

	void Loop();


private:
	static constexpr int row = 12;
	static constexpr int col = 12;

	sf::RenderWindow *pWindow;
	sf::RectangleShape mRect;
	sf::RectangleShape aCells[row*col];
	int aCounter[row*col];
	sf::Clock clock;

};

