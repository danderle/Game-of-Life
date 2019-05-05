#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>

#include <SFML/Graphics.hpp>

class State
{
public:
	State() = delete;
	State(sf::RenderWindow *window);
	virtual ~State();

	virtual void EndState() = 0;
	virtual void Update(const float dt) = 0;
	virtual void Draw(sf::RenderTarget *target = nullptr) = 0;

private:
	std::vector<sf::Texture> vTextures;
	sf::RenderWindow *pWindow;
};

