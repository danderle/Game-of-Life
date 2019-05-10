#pragma once
#include "State.h"
class MainMenuState : public State
{
public:
	MainMenuState() = delete;
	MainMenuState(sf::RenderWindow *window, std::map<std::string, unsigned int>* inputKeys);
	virtual ~MainMenuState();

	void EndState();
	void UpdateInput(const float dt = 0);
	void Update(const float dt);
	void Draw(sf::RenderWindow *window = nullptr);

private:
	void InitFrame(const unsigned int windowWidth, const unsigned int windowHeight);
	void InitKeyBinds();
};

