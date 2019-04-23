#include "Game.h"


Game::Game(const unsigned int windowWidth, const unsigned int windowHeight, const std::string &windowTitle)
{
	pWindow = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle);



	mRect.setSize(sf::Vector2f(550.0f, 550.0f));
	mRect.setFillColor(sf::Color::Transparent);
	mRect.setOutlineColor(sf::Color::Green);
	mRect.setOutlineThickness(10.0f);
	mRect.setOrigin(sf::Vector2f(275.f, 275.f));
	mRect.setPosition(sf::Vector2f((float)windowWidth / 2.f, (float)windowHeight / 2.f));

	int yOffset = 0;
	for (int x = 0; x < 100; x++)
	{
		aCells[x].setSize(sf::Vector2f(55.f, 55.f));
		aCells[x].setFillColor(sf::Color::Transparent);
		aCells[x].setOutlineColor(sf::Color::Blue);
		aCells[x].setOutlineThickness(-2.0f);
		aCells[x].setOrigin(sf::Vector2f(55.0f/2.0f, 55.0f/2.0f));
		float xOffset = (x % 10 + 1);
		if (x % 10 == 0)
		{
			yOffset++;
			aCells[x].setPosition(sf::Vector2f(xOffset*(aCells[x].getSize().x) - 2.5f, yOffset*(aCells[x].getSize().y) - 2.5f));
		}
		else
		{
			aCells[x].setPosition(sf::Vector2f(xOffset*(aCells[x].getSize().x) - 2.5f, yOffset*(aCells[x].getSize().y) - 2.5f));
		}
	}
}


Game::~Game()
{
}

void Game::Loop()
{
	while (pWindow->isOpen())
	{
		sf::Event event;
		while (pWindow->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				pWindow->close();
				break;
			}
		}

		pWindow->clear();
		pWindow->draw(mRect);
		for (auto cell : aCells)
		{
			pWindow->draw(cell);
		}
		pWindow->display();
	}
}
