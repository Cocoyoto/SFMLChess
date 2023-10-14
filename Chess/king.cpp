#include "king.hpp"

King::King(const chessColor color, const sf::Vector2u position) :
	Piece(color, position)
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

void King::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept
{
	int x = m_position.x;
	int y = m_position.y;
	int imax = std::min((int)board.size()-1, x + 1);
	int jmax = std::min((int)board.size()-1, y + 1);

	for (int i = std::max(x - 1, 0); i <= imax; ++i)
	{
		for (int j= std::max(y - 1, 0); j <= jmax; ++j)
		{
			if (i == x && j == y)
			{
				continue;
			}

			if (board[i][j] == nullptr)
			{
				m_possibleMoves.push_back(sf::Vector2u(i, j));
			}
			else if (board[i][j]->getPieceColor() != getPieceColor())
			{
				m_possibleMoves.push_back(sf::Vector2u(i, j));
			}
		}
	}
}