#include "rook.hpp"

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
