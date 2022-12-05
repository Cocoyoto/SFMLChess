#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "piece.hpp"

using std::vector;

const int BOARD_SIZE = 8;
const int WINDOW_SIZE = 900;
const int MARGIN = 50;

const double SQUARE_SIZE = (WINDOW_SIZE - MARGIN * 2.0) / BOARD_SIZE;
const double FULLBOARD_SIZE = WINDOW_SIZE - MARGIN * 2.0;

const int scalePiece = SQUARE_SIZE / 32;
const int pieceGap = (SQUARE_SIZE - (16 * scalePiece * 1.0)) / 2;

const std::string FONT_NAME = "rainyhearts.ttf";

const sf::Color DARK (69, 76, 94, 255);
const sf::Color BRIGHT (230, 234, 215, 255);
const sf::Color OUTLINE = BRIGHT;

enum files { A, B, C, D, E, F, G, H };

class board
{
public :
	board();

	~board();

	void draw();
private:
	
	void drawChessOutline();
	void drawChessBoard();
	void drawCoordinates();
	void drawPieces();

	void initPieces();
	
	sf::RenderWindow m_window;
	sf::Font m_font;
	vector<vector<piece*>> m_board;//[A][8] == [0][0]
	vector<vector<bool>> m_colorBoard;//true for white , false for black
};