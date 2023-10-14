#include "bishop.hpp"

Bishop::Bishop(const chessColor color, const sf::Vector2u position) :
	Piece(color, position)
{

}

Bishop::~Bishop()
{

}

chessPieces Bishop::getChessPiece() const noexcept
{
	return BISHOP;
}

unsigned int Bishop::getPoints() const noexcept
{
	return 3;
}

char Bishop::getFenPiece() const noexcept
{
	if (getPieceColor() == WHITE)
	{
		return 'B';
	}
	else
	{
		return 'b';
	}
}

void Bishop::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept
{
	int x = m_position.x;
	int y = m_position.y;

	// Down left
	while (x > 0 && y > 0)
	{
		x--;
		y--;

		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else
		{
			if (board[x][y]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x, y));
			}

			break;
		}
	}

	x = m_position.x;
	y = m_position.y;
	
	// Down right
	while (x < board.size()-1 && y > 0)
	{
		x++;
		y--;

		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else
		{
			if (board[x][y]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x, y));
			}

			break;
		}
	}

	x = m_position.x;
	y = m_position.y;

	// Up left
	while (x > 0 && y < board.size() - 1)
	{
		x--;
		y++;

		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else
		{
			if (board[x][y]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x, y));
			}

			break;
		}
	}

	x = m_position.x;
	y = m_position.y;

	// Up right
	while (x < board.size() - 1 && y < board.size() - 1)
	{
		x++;
		y++;

		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else
		{
			if (board[x][y]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x, y));
			}

			break;
		}
	}
}
