#include "queen.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "king.hpp"

Queen::Queen(const chessColor color, const sf::Vector2u position) :
	Piece(color, position)
{

}

Queen::~Queen()
{

}

chessPieces Queen::getChessPiece() const noexcept
{
	return QUEEN;
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

bool Queen::doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept
{
	return Rook::rookCheck(board, m_position, king) || Bishop::bishopCheck(board, m_position, king);
}

void Queen::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept
{
	if (m_king->isInCheck() == 2)
	{
		return;
	}
	//white queen got problems with captures but only sometimes, with moves but only sometimes too
	Rook::rookPossibleMoves(board, pieces, this,  m_possibleMoves);
	Bishop::bishopPossibleMoves(board, pieces, this, m_possibleMoves);
}