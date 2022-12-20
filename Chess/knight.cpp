#include "knight.hpp"

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
