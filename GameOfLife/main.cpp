#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Game Of Life"
int main(void)
{
	
	Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	game.Loop();

	return EXIT_SUCCESS;
}