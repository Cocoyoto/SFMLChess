#include "pawn.hpp"
#include "king.hpp"

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

bool Pawn::doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept
{
	return pawnCheck(m_position, king);
}

bool Pawn::pawnCheck(const sf::Vector2u& piecePosition, const King* king) noexcept
{
	sf::Vector2u kingPosition = king->getPosition();
	//if king is black, pawn is white so he increase his y position when he moves
	if (king->getPieceColor() == BLACK)
	{
		if (kingPosition.y == piecePosition.y + 1)
		{
			if (kingPosition.x == piecePosition.x + 1 || kingPosition.x == piecePosition.x - 1)
			{
				return true;
			}
		}
	}
	else
	{
		if (kingPosition.y == piecePosition.y - 1)
		{
			if (kingPosition.x == piecePosition.x + 1 || kingPosition.x == piecePosition.x - 1)
			{
				return true;
			}
		}
	}

	return false;
}

void Pawn::pawnPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, Piece* piece, std::vector<sf::Vector2u>& possibleMoves) noexcept
{
	sf::Vector2u m_position = piece->getPosition();
	int x = m_position.x;
	int y = m_position.y;
	King* m_king = piece->getKing();

	std::vector<std::vector<Piece*>> boardCopy(board.begin(), board.end());

	if (piece->getPieceColor() == BLACK)
	{
		if (y > 0)
		{
			if (board[x][y - 1] == nullptr)
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y - 1));
			}

			if (x > 0)
			{
				if (board[x - 1][y - 1] != nullptr && board[x - 1][y - 1]->getPieceColor() == WHITE)
				{
					piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x - 1, y - 1));
				}
			}

			if (x < board.size() - 1)
			{
				if (board[x + 1][y - 1] != nullptr && board[x + 1][y - 1]->getPieceColor() == WHITE)
				{
					piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x + 1, y - 1));
				}
			}
		}

		if (y == board.size() - 2)
		{
			if (board[x][y - 1] == nullptr && board[x][y - 2] == nullptr)
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y - 2));
			}
		}
	}
	else
	{
		if (y < board.size() - 1)
		{
			if (board[x][y + 1] == nullptr)
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y + 1));
			}

			if (x > 0)
			{
				if (board[x - 1][y + 1] != nullptr && board[x - 1][y + 1]->getPieceColor() == BLACK)
				{
					piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x - 1, y + 1));
				}
			}

			if (x < board.size() - 1)
			{
				if (board[x + 1][y + 1] != nullptr && board[x + 1][y + 1]->getPieceColor() == BLACK)
				{
					piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x + 1, y + 1));
				}
			}
		}

		if (y == 1)
		{
			if (board[x][y + 1] == nullptr && board[x][y + 2] == nullptr)
			{
				piece->addMove(boardCopy, pieces, possibleMoves, sf::Vector2u(x, y + 2));
			}
		}
	}
}

void Pawn::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept
{
	if (m_king->isInCheck() == 2)
	{
		return;
	}

	pawnPossibleMoves(board, pieces, this, m_possibleMoves);
}