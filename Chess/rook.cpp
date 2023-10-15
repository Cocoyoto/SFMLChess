#include "rook.hpp"
#include "king.hpp"

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

bool Rook::doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept
{
	return (rookCheck(board, m_position, king));
}

bool Rook::rookCheck(const std::vector<std::vector<Piece*>>& board, const sf::Vector2u& piecePosition, King* king) noexcept
{
	int x = piecePosition.x;
	int y = piecePosition.y;
	int xKing = king->getPosition().x;
	int yKing = king->getPosition().y;

	//up
	if (x == xKing && y < yKing)
	{
		for (int i = y + 1; i < yKing; ++i)
		{
			if (board[x][i] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	//down
	else if (x == xKing && y > yKing)
	{
		for (int i = y - 1; i > yKing; --i)
		{
			if (board[x][i] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	//right
	else if (x < xKing && y == yKing)
	{
		for (int i = x + 1; i < xKing; ++i)
		{
			if (board[i][y] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	//left
	else if (x > xKing && y == yKing)
	{
		for (int i = x - 1; i > xKing; --i)
		{
			if (board[i][y] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
		
	return false;
}

void Rook::rookPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, Piece* piece, std::vector<sf::Vector2u>& possibleMoves) noexcept
{
	sf::Vector2u m_position = piece->getPosition();
	int x = m_position.x;
	int y = m_position.y;
	King* m_king = piece->getKing();

	std::vector<std::vector<Piece*>> boardCopy(board.begin(), board.end());

	//up
	for (int i = y + 1; i < board.size(); ++i)
	{
		if (board[x][i] == nullptr)
		{
			piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, i));
		}
		else
		{
			if (board[x][i]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, i));
			}
			break;
		}
	}

	//down
	for (int i = y - 1; i >= 0; --i)
	{
		if (board[x][i] == nullptr)
		{
			piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, i));
		}
		else
		{
			if (board[x][i]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, i));
			}
			break;
		}
	}

	//right
	for (int i = x + 1; i < board.size(); ++i)
	{
		if (board[i][y] == nullptr)
		{
			piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(i, y));
		}
		else
		{
			if (board[i][y]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(i, y));
			}
			break;
		}
	}

	//left
	for (int i = x - 1; i >= 0; --i)
	{
		if (board[i][y] == nullptr)
		{
			piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(i, y));
		}
		else
		{
			if (board[i][y]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(i, y));
			}
			break;
		}
	}
}

void Rook::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept
{
	if (m_king->isInCheck() == 2)
	{
		return;
	}

	rookPossibleMoves(board, pieces, this, m_possibleMoves);
}