#include "piece.hpp"
#include "king.hpp"

Piece::Piece(const chessColor color, const sf::Vector2u position) :
	m_color{ color },
	m_position{ position },
	m_isPossibleMooveActualized{ false },
	m_possibleMoves{ },
	m_king{ nullptr }
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

std::vector<sf::Vector2u>& Piece::getPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept
{
	if (!m_isPossibleMooveActualized)
	{
		m_isPossibleMooveActualized = true;
		updatePossibleMoves(board, pieces);
	}

	return m_possibleMoves;
}

King* Piece::getKing() const noexcept
{
	return m_king;
}

void Piece::clearMoves() noexcept
{
	m_isPossibleMooveActualized = false;
	m_possibleMoves.clear();
}

void Piece::setPosition(const sf::Vector2u& position) noexcept
{
	m_position = position;
}

void Piece::setKing(King* king) noexcept
{
	m_king = king;
}

bool Piece::addMove(std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, std::vector<sf::Vector2u>& possibleMoves, sf::Vector2u move)
{
	bool ret;
	int x = m_position.x;
	int y = m_position.y;
	int i = move.x;
	int j = move.y;

	Piece* captured = board[i][j];
	board[i][j] = board[x][y];
	board[x][y] = nullptr;

	sf::Vector2u PiecePosition = getPosition();
	m_position.x = i;
	m_position.y = j;
	if (ret =Piece::isMoveLegal(pieces, getKing(), board, captured))
	{
		possibleMoves.push_back(sf::Vector2u(i, j));
	}

	board[x][y] = board[i][j];
	board[i][j] = nullptr;
	m_position = PiecePosition;

	return ret;
}

bool Piece::isMoveLegal(const std::vector<std::forward_list<Piece*>>& pieces, King* king, const std::vector<std::vector<Piece*>>& board, const Piece* captured) noexcept
{
	for (const auto& list : pieces)
	{
		if ((*(list.begin()))->getPieceColor() == king->getPieceColor())
		{
			continue;
		}

		for (const auto& p : list)
		{
			if (captured == p)
			{
				continue;
			}

			if (p->doesCheck(board, king))
			{
				return false;
			}
		}
	}

	return true;

}