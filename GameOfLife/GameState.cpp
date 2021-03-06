#include "GameState.h"


GameState::GameState(sf::RenderWindow *window, std::map<std::string, unsigned>* inputKeys, std::stack<State*> *states)
	:
	State(window, inputKeys, states)
{
	InitKeyBinds();
	InitFrame(pWindow->getSize().x, pWindow->getSize().y);
	InitGrid(mFrame.getGlobalBounds().width, mFrame.getGlobalBounds().height);
}


GameState::~GameState()
{
	delete pGrid;
	pGrid = nullptr;
}

void GameState::UpdateInput(const float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(maKeyBinds.at("LControl"))) && sf::Mouse::isButtonPressed(sf::Mouse::Button(maKeyBinds.at("Left_Mouse"))))
	{
		pGrid->Fill(pWindow);
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Button(maKeyBinds.at("Left_Mouse"))))
	{
		pGrid->Erase(pWindow);
	}

	//Press Enter to update the grid
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(maKeyBinds.at("Update_Grid"))))
	{
		pGrid->Update();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(maKeyBinds.at("Quit"))))
		EndState();

}

void GameState::Update(const float dt)
{
	UpdateMousePosition();
	UpdateInput(dt);
}

void GameState::Draw(sf::RenderWindow * window)
{
	if (!window)
		window = pWindow;
	pGrid->Draw(window);
	window->draw(mFrame);
}

void GameState::InitFrame(const unsigned int windowWidth, const unsigned int windowHeight)
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

void GameState::InitGrid(const float frameWidth, const float frameHeight)
{
	float startX = 50.f / 2.f;
	float startY = 75.f;
	pGrid = new Grid(frameWidth, frameHeight, startX, startY);
}

void GameState::InitKeyBinds()
{
	maKeyBinds.emplace("Update_Grid", maInputKeys->at("Enter"));
	maKeyBinds.emplace("Left_Mouse", maInputKeys->at("Left"));
	maKeyBinds.emplace("Quit", maInputKeys->at("Escape"));
	maKeyBinds.emplace("LControl", maInputKeys->at("LControl"));
}
