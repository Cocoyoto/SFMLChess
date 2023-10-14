#pragma once

#include "renderer.hpp"
#include "board.hpp"

class Piece;
enum chessColor;

class Controller
{
public:
	Controller()=delete;
	Controller(Renderer* rend, Board* board);
	Controller(Renderer* rend, Board* board, chessColor ColorToPlay);
	~Controller();

	bool update();

private:
	Renderer* m_rend;
	Board* m_board;
	Piece* m_pieceFocused;
	chessColor m_colorToPlay;

	void handleClick(const sf::Event& event);
};