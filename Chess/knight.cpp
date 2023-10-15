#include "knight.hpp"
#include "king.hpp"

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

bool Knight::doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept
{
	return knightCheck(board, m_position, king);
}

bool Knight::knightCheck(const std::vector<std::vector<Piece*>>& board, const sf::Vector2u& piecePosition, const King* king) noexcept
{
	int x = piecePosition.x;
	int y = piecePosition.y;
	int xKing = king->getPosition().x;
	int yKing = king->getPosition().y;

	// Down
	if (y - 2 == yKing)
	{
		// Left
		if (x - 1 == xKing)
		{
			return true;
		}

		// Right
		if (x + 1 == xKing)
		{
			return true;
		}
	}
	// Up
	else if (y + 2 == yKing)
	{
		// Left
		if (x - 1 == xKing)
		{
			return true;
		}

		// Right
		if (x + 1 == xKing)
		{
			return true;
		}
	}
	// Left
	else if (x - 2 == xKing)
	{
		// Down
		if (y - 1 == yKing)
		{
			return true;
		}

		// Up
		if (y + 1 == yKing)
		{
			return true;
		}
	}
	// Right
	else if (x + 2 == xKing)
	{
		// Down
		if (y - 1 == yKing)
		{
			return true;
		}

		// Up
		if (y + 1 == yKing)
		{
			return true;
		}
	}

	return false;
}

void Knight::knightPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, Piece* piece, std::vector<sf::Vector2u>& possibleMoves) noexcept
{
	sf::Vector2u m_position = piece->getPosition();
	int x = m_position.x;
	int y = m_position.y;
	King* m_king = piece->getKing();

	std::vector<std::vector<Piece*>> boardCopy(board.begin(), board.end());

	// Down
	if (y - 2 >= 0)
	{
		// Left
		if (x - 1 >= 0)
		{
			if (board[x - 1][y - 2] == nullptr || board[x - 1][y - 2]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x - 1 , y - 2));
			}
		}

		// Right
		if (x + 1 < board.size())
		{
			if (board[x + 1][y - 2] == nullptr || board[x + 1][y - 2]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x + 1, y - 2));
			}
		}
	}

	// Up
	if (y + 2 < board.size())
	{
		// Left
		if (x - 1 >= 0)
		{
			if (board[x - 1][y + 2] == nullptr || board[x - 1][y + 2]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x - 1, y + 2));
			}
		}

		// Right
		if (x + 1 < board.size())
		{
			if (board[x + 1][y + 2] == nullptr || board[x + 1][y + 2]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x + 1, y + 2));
			}
		}
	}

	// Left
	if (x - 2 >= 0)
	{
		// Down
		if (y - 1 >= 0)
		{
			if (board[x - 2][y - 1] == nullptr || board[x - 2][y - 1]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x - 2, y - 1));
			}
		}

		// Up
		if (y + 1 < board.size())
		{
			if (board[x - 2][y + 1] == nullptr || board[x - 2][y + 1]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x - 2, y + 1));
			}
		}
	}

	// Right
	if (x + 2 < board.size())
	{
		// Down
		if (y - 1 >= 0)
		{
			if (board[x + 2][y - 1] == nullptr || board[x + 2][y - 1]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x + 2, y - 1));
			}
		}

		// Up
		if (y + 1 < board.size())
		{
			if (board[x + 2][y + 1] == nullptr || board[x + 2][y + 1]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x + 2, y + 1));
			}
		}
	}
}

void Knight::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept
{
	if (m_king->isInCheck() == 2)
	{
		return;
	}

	knightPossibleMoves(board, pieces, this, m_possibleMoves);
}