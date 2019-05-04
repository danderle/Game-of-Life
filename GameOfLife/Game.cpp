#include "Game.h"

Game::Game()
{

	std::ifstream fileInput("Config/window.ini");

	std::string title = "Need Title";
	sf::VideoMode windowSize(850, 850);
	unsigned int framerateLimit = 120;
	bool verticalSyncEnabled = false;

	if (fileInput.is_open())
	{
		std::getline(fileInput, title);
		fileInput >> windowSize.width >> windowSize.height;
		fileInput >> framerateLimit;
		fileInput >> verticalSyncEnabled;
	}
	InitWindow(windowSize.width, windowSize.height, title);
	pWindow->setFramerateLimit(framerateLimit);
	pWindow->setVerticalSyncEnabled(verticalSyncEnabled);

	InitFrame(windowSize.width, windowSize.height);
	InitGrid(mFrame.getGlobalBounds().width, mFrame.getGlobalBounds().height);

	
}

Game::~Game()
{
	delete pWindow;
	pWindow = nullptr;
	delete pGrid;
	pGrid = nullptr;
}

void Game::UpdateDt()
{
	dt = sfClock.restart().asSeconds();
}

void Game::UpdateSFMLEvents()
{
	while (pWindow->pollEvent(sfEvent))
	{
		switch (sfEvent.type)
		{
		case sf::Event::Closed:
			pWindow->close();
			break;
		}
	}
}

void Game::Update()
{
	UpdateSFMLEvents();

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
}

void Game::Render()
{
	pWindow->clear();
	pWindow->draw(mFrame);
	pGrid->Draw(pWindow);
	pWindow->display();
}

void Game::Run()
{
	while (pWindow->isOpen())
	{
		UpdateDt();
		Update();
		Render();
	}
}

void Game::InitWindow(const unsigned int windowWidth, const unsigned int windowHeight, const std::string &windowTitle)
{
	pWindow = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle);
}

void Game::InitFrame(const unsigned int windowWidth, const unsigned int windowHeight)
{
	float frameWidth = windowWidth - 50.f;
	float frameHeight = windowHeight - 100.f;
	mFrame.setSize(sf::Vector2f(frameWidth, frameHeight));
	mFrame.setFillColor(sf::Color::Transparent);
	mFrame.setOutlineColor(sf::Color::Green);
	mFrame.setOutlineThickness(10.0f);
	mFrame.setOrigin(sf::Vector2f(frameWidth / 2.f, frameHeight / 2.f));
	mFrame.setPosition(sf::Vector2f((float)windowWidth / 2.f, (float)windowHeight / 2.f + 25.f));
}

void Game::InitGrid(const float frameWidth, const float frameHeight)
{
	float startX = 50.f / 2.f;
	float startY = 75.f;
	pGrid = new Grid(frameWidth, frameHeight, startX, startY);
}
