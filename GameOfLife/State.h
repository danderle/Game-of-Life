#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class State
{
public:
	State();
	virtual ~State();

	virtual void Update() = 0;
	virtual void Render() = 0;

private:
	std::vector<sf::Texture> vTextures;
};

