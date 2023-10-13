#pragma once

#include "renderer.hpp"
#include "board.hpp"

class Controller
{
public:
	Controller()=delete;
	Controller(Renderer* rend, Board* board);
	~Controller();

	bool update();

private:
	
	Renderer* m_rend;
	Board* m_board;
	bool m_pieceFocused;
};

