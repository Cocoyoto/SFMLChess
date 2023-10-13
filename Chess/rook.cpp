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

//std::vector<sf::Vector2u> Rook::getPossibleMoves(const std::vector<std::vector<Piece*>>& board) const noexcept
//{
//	std::vector<sf::Vector2u> possibleMoves;
//}