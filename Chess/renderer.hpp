#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

#include "game.typedef.hpp"
#include "board.hpp"

const std::string FONT_NAME = "rainyhearts.ttf";


struct BoardColors {
	sf::Color dark;
	sf::Color bright;
	sf::Color outline;
	sf::Color move_preview;
	sf::Color background;
};



//const double SQUARE_SIZE = (WINDOW_SIZE - MARGIN * 2.0) / BOARD_SIZE;
//const double FULLBOARD_SIZE = WINDOW_SIZE - MARGIN * 2.0;

class Renderer
{
public:
	Renderer(const RendererConfig& config, Board* board);

	void draw() const;

	bool pollEvent(sf::Event& event);

	void closeWindow();
	bool hasWindow() const;

private :
	void drawChessOutline() const;
	void drawChessBoard() const;
	void drawCoordinates() const;
	void drawPieces() const;
	void drawPossiblesMooves() const;

	std::unique_ptr<sf::RenderWindow> m_window;
	Board* m_board;
	unsigned int m_margin;
	float m_square_size;
	float m_fullboard_size;
	sf::Font m_font;
	BoardColors m_colors;
};

