#pragma once

#include <SFML/Graphics.hpp>
#include "board.hpp"

extern const int WINDOW_SIZE;

class game
{
public:
	game();
	
	void play();

private:
	board m_board;
	sf::RenderWindow m_window;
};