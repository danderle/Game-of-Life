#include "Game.h"
#include <iostream>

Game::Game(const unsigned int windowWidth, const unsigned int windowHeight, const std::string &windowTitle)
{
	pWindow = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle);


	mRect.setSize(sf::Vector2f(550.0f, 550.0f));
	mRect.setFillColor(sf::Color::Transparent);
	mRect.setOutlineColor(sf::Color::Green);
	mRect.setOutlineThickness(10.0f);
	mRect.setOrigin(sf::Vector2f(275.f, 275.f));
	mRect.setPosition(sf::Vector2f((float)windowWidth / 2.f, (float)windowHeight / 2.f));

	
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			aCells[col * y + x].setSize(sf::Vector2f(55.f, 55.f));
			aCells[col * y + x].setFillColor(sf::Color::Transparent);
			aCells[col * y + x].setFillColor(sf::Color::Transparent);
			aCells[col * y + x].setOrigin(sf::Vector2f(55.0f / 2.0f, 55.0f / 2.0f));
			
			float xPos = aCells[col * y + x].getOrigin().x + 25.f + ((x - 1)*aCells[col * y + x].getSize().x);
			float yPos = aCells[col * y + x].getOrigin().y + 25.f + ((y - 1)*aCells[col * y + x].getSize().y);
			aCells[col * y + x].setPosition(sf::Vector2f(xPos, yPos));

			//Walls are dead
			if (y != 0 && y != row - 1 && x != 0 && x != col - 1)
			{
				aCells[col * y + x].setOutlineColor(sf::Color::Blue);
				aCells[col * y + x].setOutlineThickness(2.f);
			}
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int y = 0; y < row; y++)
			{
				for (int x = 0; x < col; x++)
				{

					sf::Mouse mouse;
					if (aCells[row * y + x].getGlobalBounds().contains(pWindow->mapPixelToCoords(sf::Mouse::getPosition(*pWindow))))
					{
						aCells[row * y + x].setFillColor(sf::Color::White);
					}
				}
			}
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int y = 0; y < row; y++)
			{
				for (int x = 0; x < col; x++)
				{
					sf::Mouse mouse;
					if (aCells[row * y + x].getGlobalBounds().contains(pWindow->mapPixelToCoords(sf::Mouse::getPosition(*pWindow))))
					{
						aCells[row * y + x].setFillColor(sf::Color::Transparent);
					}
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			for (int y = 1; y < row - 1; y++)
			{
				for (int x = 1; x < col - 1; x++)
				{
					int counter = 0;
					counter += aCells[row * y + (x - 1)].getFillColor() == sf::Color::White ? 1 : 0;
					counter += aCells[row * y + (x + 1)].getFillColor() == sf::Color::White ? 1 : 0;

					counter += aCells[row * (y - 1) + (x - 1)].getFillColor() == sf::Color::White ? 1 : 0;
					counter += aCells[row * (y + 1) + (x - 1)].getFillColor() == sf::Color::White ? 1 : 0;
					counter += aCells[row * (y - 1) + x].getFillColor() == sf::Color::White ? 1 : 0;
					counter += aCells[row * (y + 1) + x].getFillColor() == sf::Color::White ? 1 : 0;
					counter += aCells[row * (y - 1) + (x + 1)].getFillColor() == sf::Color::White ? 1 : 0;
					counter += aCells[row * (y + 1) + (x + 1)].getFillColor() == sf::Color::White ? 1 : 0;

					aCounter[row * y + x] = counter;
					
				}
			}

			for (int y = 1; y < row - 1; y++)
			{
				for (int x = 1; x < col - 1; x++)
				{
					if (aCells[row * y + x].getFillColor() == sf::Color::White)
					{
						if (aCounter[row * y + x] < 2 || aCounter[row * y + x] > 3)
							aCells[row * y + x].setFillColor(sf::Color::Transparent);
					}
					else
					{
						if (aCounter[row * y + x] == 3)
							aCells[row * y + x].setFillColor(sf::Color::White);
					}
				}
			}
			sf::sleep(sf::milliseconds(100));
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
