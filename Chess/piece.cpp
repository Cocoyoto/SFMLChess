#include "piece.hpp"

/*Piece::Piece(const chessPieces piece, const chessColor color, const sf::Vector2u position) :
	m_color { color },
	m_piece { piece },
	m_position { position }
	// m_possibleMooves { vector<vector<int>> (2 , vector <int> (0,0))},
	// m_firstMoove { true }
{

    // Textures::get_textures()->set_textPiece(this);
	// m_sprite.setScale(sf::Vector2f(SCALE_PIECE, SCALE_PIECE));
	// set_spritePosition(x, y);
}*/

Piece::Piece(const chessColor color, const sf::Vector2u position) :
	m_color{ color },
	m_position{ position },
	m_isPossibleMooveActualized{ false },
	m_possibleMoves{ }
{

}

Piece::~Piece()
{

}

chessColor Piece::getPieceColor() const noexcept
{
	return m_color;
}

const sf::Vector2u& Piece::getPosition() const noexcept
{
	return m_position;
}

std::string Piece::getStringPosition() const noexcept
{
	return (char)('A' + m_position.x) + std::to_string(m_position.y + 1);
}

std::vector<sf::Vector2u>& Piece::getPossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept
{
	if (!m_isPossibleMooveActualized)
	{
		m_isPossibleMooveActualized = true;
		updatePossibleMoves(board);
	}

	return m_possibleMoves;
}

void Piece::clearMooves() noexcept
{
	m_isPossibleMooveActualized = false;
	m_possibleMoves.clear();
}

void Piece::setPosition(const sf::Vector2u& position) noexcept
{
	m_position = position;
}