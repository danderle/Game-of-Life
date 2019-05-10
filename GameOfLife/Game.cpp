#include "Game.h"

//Constructor
Game::Game()
{
	InitWindow();
	InitInputKeys();
	InitStates();
}

//Destructor
Game::~Game()
{
	delete pWindow;
	pWindow = nullptr;

	while (!sStates.empty())
	{
		delete sStates.top();
		sStates.pop();
	}
}

//Public Methods

//Gets elapsed time and restarts the clock, used for framerate independent gameplay
void Game::UpdateDt()
{
	mDt = sfClock.restart().asSeconds();
}

//Handles all SFML events
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

//Handles all input and events
void Game::Update()
{
	UpdateSFMLEvents();

	//TODO Not yet used
	if (!sStates.empty())
	{
		sStates.top()->Update(mDt);
		if (sStates.top()->GetQuit())
		{
			sStates.top()->EndState();
			delete sStates.top();
			sStates.pop();
		}
	}
	//Application End
	else
	{
		pWindow->close();
	}
}

//Draws to the window
void Game::Draw()
{
	pWindow->clear();

	//Render items
	if (!sStates.empty())
	{
		sStates.top()->Draw(pWindow);
	}
	pWindow->display();
}

//Runs the game loop
void Game::Run()
{
	while (pWindow->isOpen())
	{
		UpdateDt();
		Update();
		Draw();
	}
}

//Private Methods

//Creates the window from a config file
void Game::InitWindow()
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

	pWindow = new sf::RenderWindow(windowSize, title);
	pWindow->setFramerateLimit(framerateLimit);
	pWindow->setVerticalSyncEnabled(verticalSyncEnabled);
}

void Game::InitInputKeys()
{
	maInputKeys.emplace("Escape", sf::Keyboard::Escape);
	maInputKeys.emplace("LControl", sf::Keyboard::LControl);
	maInputKeys.emplace("Enter", sf::Keyboard::Enter);
	maInputKeys.emplace("Left", sf::Mouse::Left);
}

//Creates new States
void Game::InitStates()
{
	sStates.push(new MainMenuState(pWindow, &maInputKeys));
}