#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
//#include "game.hpp"

class piece;

using std::vector;

const int BOARD_SIZE = 8;
const int MARGIN = 50;

const int WINDOW_SIZE = 900;

constexpr double SQUARE_SIZE = (WINDOW_SIZE - MARGIN * 2.0) / BOARD_SIZE;
const double FULLBOARD_SIZE = WINDOW_SIZE - MARGIN * 2.0;

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

	void draw(sf::RenderWindow& window);
private:
	
	void drawChessOutline(sf::RenderWindow& window);
	void drawChessBoard(sf::RenderWindow& window);
	void drawCoordinates(sf::RenderWindow& window);
	void drawPieces(sf::RenderWindow& window);

	void initPieces();
	
	sf::Font m_font;
	vector<vector<piece*>> m_board;//[A][8] == [0][0]
	vector<vector<bool>> m_colorBoard;//true for white , false for black
};