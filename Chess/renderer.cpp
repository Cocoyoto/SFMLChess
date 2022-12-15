#include "renderer.hpp"

Renderer::Renderer(const RendererConfig& config):
	m_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(config.window_size, config.window_size), config.window_name)),
	m_board(nullptr),
	m_margin(MARGIN),
	m_fullboardSize((float)(config.window_size - m_margin * 2.0)),
	m_squareSize(),
	m_boardRend(sf::Quads),
	m_colors {
		{ 69, 	76, 	94, 	255 },
		{ 230, 	234, 	215, 	255 },
		{ 230, 	234, 	215, 	255 },
		{ 55, 	55, 	55, 	100 },
		{ 69,	76,		94,		255 }
	},
	m_resourcesHolder{}
{
	sf::Texture chessPieces;
	chessPieces.loadFromFile("./assets/chess_pieces.png");
	m_resourcesHolder.setResource("chessPieces", chessPieces);
	m_font.loadFromFile(FONT_NAME);
}

void Renderer::changeConfig(const RendererConfig& config) noexcept
{
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(config.window_size, config.window_size), config.window_name);
	m_fullboardSize = (float)(config.window_size - m_margin * 2.0);
	m_squareSize = m_fullboardSize / m_board->getSize();
	if (m_board)
	{
		createBoardRend();
	}
}

void Renderer::changeBoard(Board* board) noexcept
{
	m_board = board;
	if (m_board)
	{
		m_squareSize = m_fullboardSize / m_board->getSize();
		createBoardRend();
	}
}

void Renderer::draw() const
{
	m_window->clear(m_colors.background);

	//drawing board
	m_window->draw(m_boardRend);

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

void Renderer::openWindow(const RendererConfig& config)
{
	if (m_window)
	{
		m_window->close();
	}
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(config.window_size, config.window_size), config.window_name);
}

void Renderer::closeWindow()
{
	if (m_window)
	{
		m_window->close();
	}
	m_window = nullptr;
}

bool Renderer::hasWindow() const
{
	return m_window != nullptr;
}


void Renderer::drawCoordinates() const
{
	sf::Text coordinate;
	coordinate.setFont(m_font);
	coordinate.setCharacterSize(m_squareSize / 3);
	coordinate.setFillColor(m_colors.bright);
	coordinate.setStyle(sf::Text::Bold);

	const double valueFiles = m_margin + (m_squareSize / 2.0) - (coordinate.getCharacterSize() / 3.0);
	const double valueRows = m_margin + (m_squareSize / 2.0) - (coordinate.getCharacterSize() / 2.0);
	const double valueBorderBot = m_window->getSize().x - m_margin;
	const double valueBorderLeft = m_margin - coordinate.getCharacterSize();
	unsigned int board_size = m_board->getSize();
	char files = 'A';

	for (unsigned int x = 0; x < board_size; ++x, ++files)
	{
		coordinate.setString(files);
		coordinate.setPosition(valueFiles + (x * m_squareSize), valueBorderBot);
		m_window->draw(coordinate);
	}
	for (unsigned int y = 0; y < board_size; ++y)
	{
		coordinate.setString(std::to_string(board_size - y));
		coordinate.setPosition(valueBorderLeft, valueRows + (y * m_squareSize));
		m_window->draw(coordinate);
	}
}

void Renderer::drawPieces() const
{

}

void Renderer::drawPossiblesMooves() const
{

}

void Renderer::createBoardRend()
{
	//adding the outline
	appendOutline(m_margin, m_margin, m_fullboardSize, m_fullboardSize, m_colors.outline, 5);
	//adding the entire board
	unsigned int board_size = m_board->getSize();
	for (unsigned int y = 0; y < board_size; ++y)
	{
		for (unsigned int x = 0; x < board_size; ++x)
		{
			if ((x + y) % 2 == 0)
			{
				appendSquare(m_margin + x * m_squareSize, m_margin + y * m_squareSize, m_squareSize, m_squareSize, m_colors.bright);
			}
			else
			{
				appendSquare(m_margin + x * m_squareSize, m_margin + y * m_squareSize, m_squareSize, m_squareSize, m_colors.dark);
			}
		}
	}
}

void Renderer::appendOutline(float x, float y, float width, float height, sf::Color color, float thickness)
{
	appendSquare(x - thickness, y - thickness, width + thickness, thickness, color);
	appendSquare(x - thickness, y, thickness, height + thickness, color);
	appendSquare(x + width, y - thickness, thickness, height + thickness, color);
	appendSquare(x, y + height, width + thickness, thickness, color);
}

void Renderer::appendSquare(float x, float y, float width, float height, sf::Color color)
{
	m_boardRend.append(sf::Vertex(sf::Vector2f(x, y), color));
	m_boardRend.append(sf::Vertex(sf::Vector2f(x+width, y), color));
	m_boardRend.append(sf::Vertex(sf::Vector2f(x+width, y+height), color));
	m_boardRend.append(sf::Vertex(sf::Vector2f(x, y+height), color));
}