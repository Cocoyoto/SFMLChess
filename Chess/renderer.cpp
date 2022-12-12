#include "renderer.hpp"

Renderer::Renderer(const RendererConfig& config, Board* board):
	m_window(nullptr),
	m_board(board),
	m_margin(50),
	m_square_size((float)(config.window_size - m_margin * 2.0) / m_board->getSize()),
	m_fullboard_size(0),
	m_colors {
		{ 69, 	76, 	94, 	255 },
		{ 230, 	234, 	215, 	255 },
		{ 230, 	234, 	215, 	255 },
		{ 55, 	55, 	55, 	100 },
		{ 69,	76,		94,		255 }
	}
{
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(config.window_size, config.window_size), config.window_name);

	m_font.loadFromFile(FONT_NAME);
}//(WINDOW_SIZE - MARGIN * 2.0) / BOARD_SIZE;
//const double FULLBOARD_SIZE = WINDOW_SIZE - MARGIN * 2.0;

void Renderer::draw() const
{
	m_window->clear(m_colors.background);
	// all m_window.draw(); here
	//drawing background
	drawChessOutline();
	drawChessBoard();

	//writting coordonates
	drawCoordinates();

	//drawing pieces
	drawPieces();


	m_window->display();
}

bool Renderer::pollEvent(sf::Event& event)
{
	return m_window->pollEvent(event);
}

void Renderer::closeWindow()
{
	m_window->close();
	m_window = nullptr;
}

bool Renderer::hasWindow() const
{
	return m_window != nullptr;
}

void Renderer::drawChessOutline() const
{
	//drawing the outline
	sf::RectangleShape boardOutline(sf::Vector2f(m_fullboard_size, m_fullboard_size));
	boardOutline.setPosition(m_margin, m_margin);
	boardOutline.setOutlineThickness(5);
	boardOutline.setOutlineColor(m_colors.outline);
	boardOutline.setFillColor(sf::Color::Transparent);
	m_window->draw(boardOutline);
}

void Renderer::drawChessBoard() const
{

}

void Renderer::drawCoordinates() const
{

}

void Renderer::drawPieces() const
{

}

void Renderer::drawPossiblesMooves() const
{

}