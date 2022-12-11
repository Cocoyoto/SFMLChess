#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Piece;

using std::vector;

const int BOARD_SIZE = 8;
const int MARGIN = 50;

const int WINDOW_SIZE = 900;

const double SQUARE_SIZE = (WINDOW_SIZE - MARGIN * 2.0) / BOARD_SIZE;
const double FULLBOARD_SIZE = WINDOW_SIZE - MARGIN * 2.0;


const std::string FONT_NAME = "rainyhearts.ttf";


/*enum struct Colors {
	DARK = sf::Color(69, 76, 94, 25);
BRIGHT = sf::Color(230, 234, 215, 255);
OUTLINE = sf::Color(230, 234, 215, 255);
MOVE_PREVIEW = sf::Color(55, 55, 55, 100);
};*/

const sf::Color DARK(69, 76, 94, 255);
const sf::Color BRIGHT (230, 234, 215, 255);
const sf::Color OUTLINE = BRIGHT;
const sf::Color MOOVE_PREVIEW (55, 55, 55, 100);

enum files { A, B, C, D, E, F, G, H };

class Board
{
public :
	Board();

	~Board();

	void draw(sf::RenderWindow& window);

	void FENreader(std::string fen);

	void clic(int x, int y, bool WHITEToPlay);
private:
	
	void drawChessOutline(sf::RenderWindow& window);
	void drawChessBoard(sf::RenderWindow& window);
	void drawCoordinates(sf::RenderWindow& window);
	void drawPieces(sf::RenderWindow& window);
	void drawPossiblesMooves(sf::RenderWindow& window);

	void initPieces();
	
	sf::Font m_font;
	vector<vector<Piece*>> m_board;//[A][8] == [0][0]
	vector<vector<bool>> m_colorBoard;//true for WHITE , false for BLACK
	Piece* m_focusedPiece;
};