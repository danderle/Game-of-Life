#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>

#include <SFML/Graphics.hpp>

class State
{
public:
	State() = delete;
	State(sf::RenderWindow *window, std::map<std::string, unsigned int>* inputKeys, std::stack<State*> *states);
	virtual ~State();

	virtual void EndState();
	virtual void UpdateMousePosition();
	virtual void UpdateInput(const float dt = 0) = 0;
	virtual void Update(const float dt) = 0;
	virtual void Draw(sf::RenderWindow *window = nullptr) = 0;

	const bool GetQuit() const;

protected:
	virtual void InitKeyBinds() = 0;

	std::stack<State*> *sStates;
	std::vector<sf::Texture> vTextures;
	sf::RenderWindow *pWindow;
	sf::Vector2i mMousePosScreen;
	sf::Vector2i mMousePosWindow;
	sf::Vector2f mMousePosView;


	std::map<std::string, unsigned int> *maInputKeys;
	std::map<std::string, unsigned int> maKeyBinds;

	bool mQuit;
};

