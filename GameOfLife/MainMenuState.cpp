#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow * window, std::map<std::string, unsigned int>* inputKeys, std::stack<State*> *states)
	:
	State(window, inputKeys, states)
{
	InitKeyBinds();
	InitFonts();
	InitButtons();
}

MainMenuState::~MainMenuState()
{
	for (auto &button : mButtons)
	{
		delete button.second;
		button.second = nullptr;
	}
}


void MainMenuState::UpdateInput(const float dt)
{
	
}

void MainMenuState::UpdateButtons()
{
	for (auto &it : mButtons)
	{
		it.second->Update(mMousePosView);
	}

	//New Game
	if (mButtons.at("GAME_STATE")->IsPressed())
	{
		sStates->push(new GameState(pWindow, maInputKeys, sStates));
	}

	//Quit game
	if (mButtons.at("EXIT_STATE")->IsPressed())
	{
		mQuit = true;
	}
}

void MainMenuState::Update(const float dt)
{
	UpdateMousePosition();
	UpdateInput(dt);
	UpdateButtons();
}

void MainMenuState::Draw(sf::RenderWindow * window)
{
	if (!window)
		window = pWindow;
	window->clear(sf::Color::Magenta);
	DrawButtons(window);
}

void MainMenuState::DrawButtons(sf::RenderWindow * window)
{
	for (auto &it : mButtons)
	{
		it.second->Draw(window);
	}
}

void MainMenuState::InitFrame(const unsigned int windowWidth, const unsigned int windowHeight)
{
}

void MainMenuState::InitKeyBinds()
{
	maKeyBinds.emplace("Quit", maInputKeys->at("Escape"));
}

void MainMenuState::InitFonts()
{
	
	if (!mFont.loadFromFile(FONT_FILEPATH))
	{
		throw("Main Menu could not load font");
	}
	mText.setFont(mFont);
}

void MainMenuState::InitButtons()
{
	mButtons["GAME_STATE"] = new Button(100, 100, 200, 150, &mFont, "New Game",
		sf::Color(0, 255, 0), sf::Color(0, 0, 255), sf::Color::Black);

	mButtons["SETTINGS_STATE"] = new Button(100, 300, 200, 150, &mFont, "Settings",
		sf::Color(0, 255, 0), sf::Color(0, 0, 255), sf::Color::Black);

	mButtons["EXIT_STATE"] = new Button(100, 500, 200, 150, &mFont, "Quit",
		sf::Color(100, 100, 100), sf::Color(150, 150, 150), sf::Color::Black);
}
