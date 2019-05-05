#pragma once
#include <SFML/Graphics.hpp>

class Asset
{
public:
	Asset();
	virtual ~Asset();

	virtual void Update(const float dt) = 0;
	virtual void Draw(sf::RenderTarget *window) = 0;

protected:
	sf::RectangleShape mShape;
};

