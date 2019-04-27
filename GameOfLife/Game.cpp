#include "Game.h"
#include <iostream>

Game::Game(const unsigned int windowWidth, const unsigned int windowHeight, const std::string &windowTitle)
{
	pWindow = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle);

	float frameWidth = windowWidth - 50.f;
	float frameHeight = windowHeight - 100.f;
	mRect.setSize(sf::Vector2f(frameWidth, frameHeight));
	mRect.setFillColor(sf::Color::Transparent);
	mRect.setOutlineColor(sf::Color::Green);
	mRect.setOutlineThickness(10.0f);
	mRect.setOrigin(sf::Vector2f(frameWidth / 2.f, frameHeight / 2.f));
	mRect.setPosition(sf::Vector2f((float)windowWidth / 2.f, (float)windowHeight / 2.f + 25.f));

	float startX = 50.f / 2.f;
	float startY = 75.f;
	pGrid = new Grid(frameWidth, frameHeight, startX, startY);
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


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			pGrid->Fill(pWindow);
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			pGrid->Erase(pWindow);
		}

		//Press Enter to update the grid
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			pGrid->Update();
		}

		pWindow->clear();
		pWindow->draw(mRect);
		pGrid->Draw(pWindow);
		pWindow->display();
	}
}
