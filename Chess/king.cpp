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
	return PAWN;
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
