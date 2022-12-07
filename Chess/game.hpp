#pragma once

#include <SFML/Graphics.hpp>
#include "board.hpp"

extern const int WINDOW_SIZE;

class Game
{
public:
	Game();
	
	void play();

private:
	Board m_board;
	sf::RenderWindow m_window;
};