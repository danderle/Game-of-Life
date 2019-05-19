#pragma once
#include "State.h"
#include "Button.h"

#define FONT_FILEPATH "Fonts/Montserrat-Regular.ttf"

class MainMenuState : public State
{
public:
	MainMenuState() = delete;
	MainMenuState(sf::RenderWindow *window, std::map<std::string, unsigned int>* inputKeys);
	virtual ~MainMenuState();

	void EndState();
	void UpdateInput(const float dt = 0);
	void UpdateButtons();
	void Update(const float dt);
	void Draw(sf::RenderWindow *window = nullptr);
	void DrawButtons(sf::RenderWindow *window);

private:
	void InitFrame(const unsigned int windowWidth, const unsigned int windowHeight);
	void InitKeyBinds();
	void InitFonts();
	void InitButtons();

	sf::Font mFont;
	sf::Text mText;

	std::map<std::string, Button*> mButtons;
};

