#pragma once

#include "board.hpp"

class game
{
public:
	game();
	
	void play();

private:
	board m_board;
};