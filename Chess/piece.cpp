#include "piece.hpp"
#include "textures.hpp"
#include "board.hpp"

Piece::Piece(chessPieces piece, chessColor color, int x, int y):
	m_piece{piece},
	m_color{color},
	m_files{x},
	m_rows{y}
{
    Textures::get_textures()->set_textPiece(this);
	m_sprite.setScale(sf::Vector2f(m_scalePiece, m_scalePiece));
	set_spritePosition(x, y);
}

chessPieces Piece::get_piece() const
{
	return m_piece;
}

chessColor Piece::get_color() const
{
	return m_color;
}

sf::Sprite& Piece::get_sprite()
{
    return m_sprite;
}

void Piece::set_piece(chessPieces chesspiece)
{
	m_piece = chesspiece;
	Textures::get_textures()->set_textPiece(this);
}

void Piece::moove_piece(int x, int y)
{
	m_files = x;
	m_rows = y;
	set_spritePosition(x, y);
}

void Piece::set_spritePosition(sf::Vector2f position)
{
	m_sprite.setPosition(sf::Vector2f(MARGIN + SQUARE_SIZE * position.x + m_pieceGap, (MARGIN + SQUARE_SIZE * position.y) - Y_PIECE_GAP));
}

void Piece::set_spritePosition(int x, int y)
{
	m_sprite.setPosition(sf::Vector2f(MARGIN + SQUARE_SIZE * x + m_pieceGap, (MARGIN + SQUARE_SIZE * y) - Y_PIECE_GAP));
}

void Piece::set_spriteScale(sf::Vector2f scale)
{
	m_sprite.setScale(scale);
}

void Piece::set_spriteScale(int x, int y)
{
	set_spriteScale(sf::Vector2f(x, y));
}

int Piece::get_scalePiece()
{
	return m_scalePiece;
}

int Piece::get_pieceGap()
{
	return m_pieceGap;
}