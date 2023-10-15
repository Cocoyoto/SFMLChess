#include "king.hpp"

King::King(const chessColor color, const sf::Vector2u position) :
	Piece(color, position),
	m_isInCheck{ false }
{

}

King::~King()
{

}

chessPieces King::getChessPiece() const noexcept
{
	return KING;
}

unsigned int King::getPoints() const noexcept
{
	return 1;
}

char King::getFenPiece() const noexcept
{
	if (getPieceColor() == WHITE)
	{
		return 'K';
	}
	else
	{
		return 'k';
	}
}

bool King::doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept
{
	return kingCheck(m_position, king);
}

unsigned int King::isCheckMate(const std::vector<std::vector<Piece*>>& board, std::vector<std::forward_list<Piece*>>& pieces) noexcept
{//0 = not checkmate, 1 = checkmate, 2 = stalemate
	if (m_isInCheck == 2)
	{
		if (!m_isPossibleMooveActualized)
		{
			getPossibleMoves(board, pieces);
		}

		if (m_possibleMoves.empty())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	auto list = pieces[getPieceColor()];
	for (Piece* piece : list)
	{
		if (!piece->getPossibleMoves(board, pieces).empty())
		{
			return 0;
		}
		else
		{
			if (m_isInCheck == 1)
			{
				return 1;
			}
			else if (m_isInCheck == 0)
			{
				return 2;
			}
		}
	}
}

bool King::kingCheck(const sf::Vector2u& piecePosition, const King* king) noexcept
{
	int x = piecePosition.x;
	int y = piecePosition.y;
	int xKing = king->getPosition().x;
	int yKing = king->getPosition().y;

	if (x >= xKing - 1 && x <= xKing + 1 && y >= yKing - 1 && y <= yKing + 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void King::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept
{
	unsigned int check = m_isInCheck;

	kingPossibleMoves(board, pieces, this, m_possibleMoves);

	m_isInCheck = check;
}

unsigned int King::isInCheck() const noexcept
{
	return m_isInCheck;
}

unsigned int King::updateCheck(const std::vector<std::forward_list<Piece*>>& pieces, const std::vector<std::vector<Piece*>>& board) noexcept
{
	m_isInCheck = 0;

	for (const std::forward_list<Piece*>& list : pieces)
	{
		if ((*(list.begin()))->getPieceColor() == getPieceColor())
		{
			continue;
		}

		for (Piece* piece : list)
		{
			if (piece->doesCheck(board, this))
			{
				m_isInCheck++;
				if (m_isInCheck == 2)//king can't have more than double check
				{
					return 2;
				}
			}
		}
	}

	return m_isInCheck;
}

void King::kingPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, King* piece, std::vector<sf::Vector2u>& possibleMoves) noexcept
{
	sf::Vector2u m_position = piece->getPosition();
	int x = m_position.x;
	int y = m_position.y;
	int imax = std::min((int)board.size() - 1, x + 1);
	int jmax = std::min((int)board.size() - 1, y + 1);

	std::vector<std::vector<Piece*>> boardCopy(board.begin(), board.end());

	for (int i = std::max(x - 1, 0); i <= imax; ++i)
	{
		for (int j = std::max(y - 1, 0); j <= jmax; ++j)
		{
			if (i == x && j == y)
			{
				continue;
			}

			if (board[i][j] == nullptr)
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(i, j));
			}
			else if (board[i][j]->getPieceColor() != piece->getPieceColor())
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(i, j));
			}
		}
	}
}