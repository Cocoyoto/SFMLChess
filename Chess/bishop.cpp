#include "bishop.hpp"

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
