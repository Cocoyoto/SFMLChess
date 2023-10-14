#include "knight.hpp"

Knight::Knight(const chessColor color, const sf::Vector2u position) :
	Piece(color, position)
{

}

Knight::~Knight()
{

}

chessPieces Knight::getChessPiece() const noexcept
{
	return KNIGHT;
}

unsigned int Knight::getPoints() const noexcept
{
	return 3;
}

char Knight::getFenPiece() const noexcept
{
	if (getPieceColor() == WHITE)
	{
		return 'N';
	}
	else
	{
		return 'n';
	}
}

void Knight::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept
{
	int x = m_position.x;
	int y = m_position.y;

	// Down
	if (y - 2 >= 0)
	{
		// Left
		if (x - 1 >= 0)
		{
			if (board[x - 1][y - 2] == nullptr || board[x - 1][y - 2]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x - 1, y - 2));
			}
		}

		// Right
		if (x + 1 < board.size())
		{
			if (board[x + 1][y - 2] == nullptr || board[x + 1][y - 2]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x + 1, y - 2));
			}
		}
	}

	// Up
	if (y + 2 < board.size())
	{
		// Left
		if (x - 1 >= 0)
		{
			if (board[x - 1][y + 2] == nullptr || board[x - 1][y + 2]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x - 1, y + 2));
			}
		}

		// Right
		if (x + 1 < board.size())
		{
			if (board[x + 1][y + 2] == nullptr || board[x + 1][y + 2]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x + 1, y + 2));
			}
		}
	}

	// Left
	if (x - 2 >= 0)
	{
		// Down
		if (y - 1 >= 0)
		{
			if (board[x - 2][y - 1] == nullptr || board[x - 2][y - 1]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x - 2, y - 1));
			}
		}

		// Up
		if (y + 1 < board.size())
		{
			if (board[x - 2][y + 1] == nullptr || board[x - 2][y + 1]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x - 2, y + 1));
			}
		}
	}

	// Right
	if (x + 2 < board.size())
	{
		// ^Down
		if (y - 1 >= 0)
		{
			if (board[x + 2][y - 1] == nullptr || board[x + 2][y - 1]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x + 2, y - 1));
			}
		}

		// Up
		if (y + 1 < board.size())
		{
			if (board[x + 2][y + 1] == nullptr || board[x + 2][y + 1]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x + 2, y + 1));
			}
		}
	}
}