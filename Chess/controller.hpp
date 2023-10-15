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
	~Controller();

	bool update();
	void setColorToPlay(chessColor color) noexcept;

private:
	Renderer* m_rend;
	Board* m_board;
	Piece* m_pieceFocused;
	chessColor m_colorToPlay;

	void handleClick(const sf::Event& event);
};