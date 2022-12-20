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
