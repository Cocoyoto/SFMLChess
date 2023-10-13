#include "renderer.hpp"
#include "piece.hpp"

Renderer::Renderer(const RendererConfig& config):
	m_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(config.window_size, config.window_size), config.window_name)),
	m_board(nullptr),
	m_margin(MARGIN),
	m_fullboardSize((float)(config.window_size - m_margin * 2.0)),
	m_squareSize(),
	m_boardRend(sf::Quads),
	m_piecesRend(sf::Quads),
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
		createPiecesRend();
	}
}

void Renderer::changeBoard(Board* board) noexcept
{
	m_board = board;
	if (m_board)
	{
		m_squareSize = m_fullboardSize / m_board->getSize();
		createBoardRend();
		createPiecesRend();
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
	m_window->draw(m_piecesRend, m_resourcesHolder.getResource("chessPieces"));


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

void Renderer::piecesEdit() noexcept
{
	createPiecesRend();
}

void Renderer::clic(float x, float y) noexcept
{
	auto& pieces = m_board->getPieces();
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

void Renderer::drawPossiblesMooves() const
{

}

void Renderer::createBoardRend() noexcept
{
	//adding the outline
	appendOutline(m_margin, m_margin, m_fullboardSize, m_fullboardSize, m_colors.outline, 5, m_boardRend);
	//adding the entire board
	unsigned int board_size = m_board->getSize();
	for (unsigned int y = 0; y < board_size; ++y)
	{
		for (unsigned int x = 0; x < board_size; ++x)
		{
			if ((x + y) % 2 == 0)
			{
				appendSquare(m_margin + x * m_squareSize, m_margin + y * m_squareSize, m_squareSize, m_squareSize, m_colors.bright, m_boardRend);
			}
			else
			{
				appendSquare(m_margin + x * m_squareSize, m_margin + y * m_squareSize, m_squareSize, m_squareSize, m_colors.dark, m_boardRend);
			}
		}
	}
}

void Renderer::createPiecesRend() noexcept
{
	const unsigned int TEXT_Y = 32;
	const unsigned int TEXT_X = 16;

	const unsigned int Y_PIECE_GAP = 0 + m_margin;
	const unsigned int SCALE_PIECE = m_squareSize / TEXT_Y;
	const unsigned int X_PIECE_GAP = ((m_squareSize - (TEXT_X * SCALE_PIECE * 1.0)) / 2) + m_margin;
	const unsigned int BOARD_SIZE = m_board->getSize();
	const unsigned int WIDTH = TEXT_X * SCALE_PIECE;
	const unsigned int HEIGHT = TEXT_Y * SCALE_PIECE;

	m_piecesRend.clear();
	auto& piecesTab = m_board->getPieces();
	unsigned int j = 0;
	for (int files = 0; files < BOARD_SIZE; ++files)
	{
		for (int rows = 0; rows < BOARD_SIZE; ++rows)
		{
			if (piecesTab[files][rows] != nullptr)
			{
				appendSquare(X_PIECE_GAP + (files * m_squareSize), Y_PIECE_GAP + ((BOARD_SIZE - 1 - rows) * m_squareSize), WIDTH, HEIGHT, m_piecesRend);

				//applying the texture
				unsigned int x = TEXT_X * piecesTab[files][rows]->getChessPiece();
				unsigned int y = TEXT_Y * piecesTab[files][rows]->getPieceColor();

				m_piecesRend[j++].texCoords = sf::Vector2f(x, y);
				m_piecesRend[j++].texCoords = sf::Vector2f(x + TEXT_X, y);
				m_piecesRend[j++].texCoords = sf::Vector2f(x + TEXT_X, y + TEXT_Y);
				m_piecesRend[j++].texCoords = sf::Vector2f(x, y + TEXT_Y);
			}
			
		}
	}
	/*for (const auto& i : piecesMap)
	{
		sf::Vector2u position = i.second->getPosition();
		appendSquare(X_PIECE_GAP + (position.x * m_squareSize), Y_PIECE_GAP + ((BOARD_SIZE - 1 - position.y) * m_squareSize), WIDTH, HEIGHT, m_piecesRend);

		//applying the texture
		unsigned int x = TEXT_X * i.second->getChessPiece();
		unsigned int y = TEXT_Y * i.second->getPieceColor();

		m_piecesRend[j++].texCoords = sf::Vector2f(x, y);
		m_piecesRend[j++].texCoords = sf::Vector2f(x + TEXT_X, y);
		m_piecesRend[j++].texCoords = sf::Vector2f(x + TEXT_X, y + TEXT_Y);
		m_piecesRend[j++].texCoords = sf::Vector2f(x, y + TEXT_Y);
	}*/
}

void Renderer::appendOutline(float x, float y, float width, float height, sf::Color color, float thickness, sf::VertexArray& VertexArray) noexcept
{
	appendSquare(x - thickness, y - thickness, width + thickness, thickness, color, VertexArray);
	appendSquare(x - thickness, y, thickness, height + thickness, color, VertexArray);
	appendSquare(x + width, y - thickness, thickness, height + thickness, color, VertexArray);
	appendSquare(x, y + height, width + thickness, thickness, color, VertexArray);
}

void Renderer::appendSquare(float x, float y, float width, float height, sf::Color color, sf::VertexArray& VertexArray) noexcept
{
	VertexArray.append(sf::Vertex(sf::Vector2f(x, y), color));
	VertexArray.append(sf::Vertex(sf::Vector2f(x+width, y), color));
	VertexArray.append(sf::Vertex(sf::Vector2f(x+width, y+height), color));
	VertexArray.append(sf::Vertex(sf::Vector2f(x, y+height), color));
}

void Renderer::appendSquare(float x, float y, float width, float height, sf::VertexArray& VertexArray) noexcept
{
	VertexArray.append(sf::Vertex(sf::Vector2f(x, y)));
	VertexArray.append(sf::Vertex(sf::Vector2f(x + width, y)));
	VertexArray.append(sf::Vertex(sf::Vector2f(x + width, y + height)));
	VertexArray.append(sf::Vertex(sf::Vector2f(x, y + height)));
}

void Renderer::appendOutline(float x, float y, float width, float height, sf::Color color, float thickness, sf::VertexArray& VertexArray) const noexcept
{
	appendSquare(x - thickness, y - thickness, width + thickness, thickness, color, VertexArray);
	appendSquare(x - thickness, y, thickness, height + thickness, color, VertexArray);
	appendSquare(x + width, y - thickness, thickness, height + thickness, color, VertexArray);
	appendSquare(x, y + height, width + thickness, thickness, color, VertexArray);
}

void Renderer::appendSquare(float x, float y, float width, float height, sf::Color color, sf::VertexArray& VertexArray) const noexcept
{
	VertexArray.append(sf::Vertex(sf::Vector2f(x, y), color));
	VertexArray.append(sf::Vertex(sf::Vector2f(x + width, y), color));
	VertexArray.append(sf::Vertex(sf::Vector2f(x + width, y + height), color));
	VertexArray.append(sf::Vertex(sf::Vector2f(x, y + height), color));
}

void Renderer::appendSquare(float x, float y, float width, float height, sf::VertexArray& VertexArray) const noexcept
{
	VertexArray.append(sf::Vertex(sf::Vector2f(x, y)));
	VertexArray.append(sf::Vertex(sf::Vector2f(x + width, y)));
	VertexArray.append(sf::Vertex(sf::Vector2f(x + width, y + height)));
	VertexArray.append(sf::Vertex(sf::Vector2f(x, y + height)));
}