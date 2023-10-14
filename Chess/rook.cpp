#include "rook.hpp"

Rook::Rook(const chessColor color, const sf::Vector2u position) :
	Piece(color, position)
{

}

Rook::~Rook()
{

}

chessPieces Rook::getChessPiece() const noexcept
{
	return ROOK;
}

unsigned int Rook::getPoints() const noexcept
{
	return 5;
}

char Rook::getFenPiece() const noexcept
{
	if (getPieceColor() == WHITE)
	{
		return 'R';
	}
	else
	{
		return 'r';
	}
}

void Rook::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept
{
	int x = m_position.x;
	int y = m_position.y;

	//up
	for (int i = y + 1; i < board.size(); ++i)
	{
		if (board[x][i] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, i));
		}
		else
		{
			if (board[x][i]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x, i));
			}
			break;
		}
	}

	//down
	for (int i = y - 1; i >= 0; --i)
	{
		if (board[x][i] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, i));
		}
		else
		{
			if (board[x][i]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(x, i));
			}
			break;
		}
	}

	//right
	for (int i = x + 1; i < board.size(); ++i)
	{
		if (board[i][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(i, y));
		}
		else
		{
			if (board[i][y]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(i, y));
			}
			break;
		}
	}

	//left
	for (int i = x - 1; i >= 0; --i)
	{
		if (board[i][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(i, y));
		}
		else
		{
			if (board[i][y]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(i, y));
			}
			break;
		}
	}
}