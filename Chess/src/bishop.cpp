#include "bishop.hpp"
#include "king.hpp"

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

bool Bishop::doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept
{
	return bishopCheck(board, m_position, king);
}

bool Bishop::bishopCheck(const std::vector<std::vector<Piece*>>& board, const sf::Vector2u& piecePosition, const King* king) noexcept
{
	int x = piecePosition.x;
	int y = piecePosition.y;
	int xKing = king->getPosition().x;
	int yKing = king->getPosition().y;
	int xDiff = xKing - x;
	int yDiff = yKing - y;

	//then bishop can go on the king position
	if (abs(xDiff) == abs(yDiff))
	{
		// Up Right
		if (xDiff > 0 && yDiff > 0)
		{
			x++;
			y++;

			while (x < xKing && y < yKing)
			{
				if (board[x][y] != nullptr)
				{
					return false;
				}

				x++;
				y++;
			}
			return true;
		}
		// Up Left
		else if (xDiff < 0 && yDiff > 0)
		{
			x--;
			y++;

			while (x > xKing && y < yKing)
			{
				if (board[x][y] != nullptr)
				{
					return false;
				}

				x--;
				y++;
			}
			return true;
		}
		// Down Right
		else if (xDiff > 0 && yDiff < 0)
		{
			x++;
			y--;

			while (x < xKing && y > yKing)
			{
				if (board[x][y] != nullptr)
				{
					return false;
				}

				x++;
				y--;
			}
			return true;
		}
		// Down Left
		else if (xDiff < 0 && yDiff < 0)
		{
			x--;
			y--;

			while (x > xKing && y > yKing)
			{
				if (board[x][y] != nullptr)
				{
					return false;
				}

				x--;
				y--;
			}
			return true;
		}
	}

	return false;
}

void Bishop::bishopPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, Piece* piece, std::vector<sf::Vector2u>& possibleMoves) noexcept
{
	sf::Vector2u m_position = piece->getPosition();
	int x = m_position.x;
	int y = m_position.y;

	std::vector<std::vector<Piece*>> boardCopy(board.begin(), board.end());

	// Down left
	while (x > 0 && y > 0)
	{
		x--;
		y--;

		if (board[x][y] == nullptr)
		{
			piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y));
		}
		else
		{
			if (board[x][y]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y));
			}

			break;
		}
	}

	x = m_position.x;
	y = m_position.y;

	// Down right
	while (x < board.size() - 1 && y > 0)
	{
		x++;
		y--;

		if (board[x][y] == nullptr)
		{
			piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y));
		}
		else
		{
			if (board[x][y]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y));
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
			piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y));
		}
		else
		{
			if (board[x][y]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y));
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
			piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y));
		}
		else
		{
			if (board[x][y]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y));
			}

			break;
		}
	}
}

void Bishop::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept
{
	if (m_king->isInCheck() == 2)
	{
		return;
	}

	bishopPossibleMoves(board, pieces, this, m_possibleMoves);
}
