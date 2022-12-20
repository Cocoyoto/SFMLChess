#include "queen.hpp"

Queen::Queen(const chessColor color, const sf::Vector2u position) :
	Piece(color, position)
{

}

Queen::~Queen()
{

}

chessPieces Queen::getChessPiece() const noexcept
{
	return PAWN;
}

unsigned int Queen::getPoints() const noexcept
{
	return 1;
}

char Queen::getFenPiece() const noexcept
{
	if (getPieceColor() == WHITE)
	{
		return 'Q';
	}
	else
	{
		return 'q';
	}
}
