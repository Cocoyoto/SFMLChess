#pragma once

#include "renderer.hpp"
#include "board.hpp"

class Controller
{
public:
	Controller()=delete;
	Controller(Renderer* rend, Board* board);
	~Controller();

	void update();

private:
	Renderer* m_rend;
	Board* m_board;
};

