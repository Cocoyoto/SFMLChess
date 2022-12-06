#include "piece.hpp"
#include "textures.hpp"
#include "board.hpp"

piece::piece(chessPieces piece, chessColor color, int x, int y):
	m_piece{piece},
	m_color{color},
	m_files{x},
	m_rows{y}
{
    textures::get_textures()->set_textPiece(this);
	m_sprite.setScale(sf::Vector2f(m_scalePiece, m_scalePiece));
	set_spritePosition(x, y);
}

chessPieces piece::get_piece() const
{
	return m_piece;
}

chessColor piece::get_color() const
{
	return m_color;
}

sf::Sprite& piece::get_sprite()
{
    return m_sprite;
}

void piece::set_piece(chessPieces chesspiece)
{
	m_piece = chesspiece;
	textures::get_textures()->set_textPiece(this);
}

void piece::moove_piece(int x, int y)
{
	m_files = x;
	m_rows = y;
	set_spritePosition(x, y);
}

void piece::set_spritePosition(sf::Vector2f position)
{
	m_sprite.setPosition(sf::Vector2f(MARGIN + SQUARE_SIZE * position.x + m_pieceGap, (MARGIN + SQUARE_SIZE * position.y) - Y_PIECE_GAP));
}

void piece::set_spritePosition(int x, int y)
{
	m_sprite.setPosition(sf::Vector2f(MARGIN + SQUARE_SIZE * x + m_pieceGap, (MARGIN + SQUARE_SIZE * y) - Y_PIECE_GAP));
}

void piece::set_spriteScale(sf::Vector2f scale)
{
	m_sprite.setScale(scale);
}

void piece::set_spriteScale(int x, int y)
{
	set_spriteScale(sf::Vector2f(x, y));
}

int piece::get_scalePiece()
{
	return m_scalePiece;
}

int piece::get_pieceGap()
{
	return m_pieceGap;
}