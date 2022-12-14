#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

#include "game.typedef.hpp"
#include "board.hpp"

const std::string FONT_NAME = "rainyhearts.ttf";
const unsigned int MARGIN = 50;


struct BoardColors {
	sf::Color dark;
	sf::Color bright;
	sf::Color outline;
	sf::Color move_preview;
	sf::Color background;
};

class Renderer
{
public:
	Renderer(const RendererConfig& config, Board* board);

	void changeConfig(const RendererConfig& config);
	void changeBoard(Board* board);

	void draw() const;

	bool pollEvent(sf::Event& event);

	void closeWindow();
	bool hasWindow() const;

private :
	//void drawChessOutline() const;
	//void drawChessBoard() const;
	void drawCoordinates() const;
	void drawPieces() const;
	void drawPossiblesMooves() const;

	void createBoardRend();
	void appendOutline(float x, float y, float width, float height, sf::Color color, float thickness);
	void appendSquare(float x, float y, float width, float height, sf::Color color);

	std::unique_ptr<sf::RenderWindow> m_window;
	Board* m_board;
	unsigned int m_margin;
	float m_fullboardSize;
	float m_squareSize;
	sf::VertexArray m_boardRend;
	sf::Font m_font;
	BoardColors m_colors;
};

