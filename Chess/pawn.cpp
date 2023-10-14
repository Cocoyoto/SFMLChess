#include "pawn.hpp"

Pawn::Pawn(const chessColor color, const sf::Vector2u position) :
	Piece(color, position)
{

}

Pawn::~Pawn()
{

}

chessPieces Pawn::getChessPiece() const noexcept
{
	return PAWN;
}

unsigned int Pawn::getPoints() const noexcept
{
	return 1;
}

char Pawn::getFenPiece() const noexcept
{
	if (getPieceColor() == WHITE)
	{
		return 'P';
	}
	else
	{
		return 'p';
	}
}

void Pawn::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept
{
	int x = m_position.x;
	int y = m_position.y;

	if (getPieceColor() == BLACK)
	{
		if (y > 0)
		{
			if (board[x][y - 1] == nullptr)
			{
				m_possibleMoves.push_back(sf::Vector2u(x, y - 1));
			}

			if (x > 0)
			{
				if (board[x - 1][y - 1] != nullptr && board[x - 1][y - 1]->getPieceColor() == WHITE)
				{
					m_possibleMoves.push_back(sf::Vector2u(x - 1, y - 1));
				}
			}

			if (x < board.size()-1)
			{
				if (board[x + 1][y - 1] != nullptr && board[x + 1][y - 1]->getPieceColor() == WHITE)
				{
					m_possibleMoves.push_back(sf::Vector2u(x + 1, y - 1));
				}
			}
		}

		if (y == board.size()-2)
		{
			if (board[x][y - 1] == nullptr && board[x][y - 2] == nullptr)
			{
				m_possibleMoves.push_back(sf::Vector2u(x, y - 2));
			}
		}
	}
	else
	{
		if (y < board.size() - 1)
		{
			if (board[x][y + 1] == nullptr)
			{
				m_possibleMoves.push_back(sf::Vector2u(x, y + 1));
			}

			if (x > 0)
			{
				if (board[x - 1][y + 1] != nullptr && board[x - 1][y + 1]->getPieceColor() == BLACK)
				{
					m_possibleMoves.push_back(sf::Vector2u(x - 1, y + 1));
				}
			}

			if (x < board.size() - 1)
			{
				if (board[x + 1][y + 1] != nullptr && board[x + 1][y + 1]->getPieceColor() == BLACK)
				{
					m_possibleMoves.push_back(sf::Vector2u(x + 1, y + 1));
				}
			}
		}

		if (y == 1)
		{
			if (board[x][y + 1] == nullptr && board[x][y + 2] == nullptr)
			{
				m_possibleMoves.push_back(sf::Vector2u(x, y + 2));
			}
		}
	}
}