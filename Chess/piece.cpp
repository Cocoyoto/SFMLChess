#include "piece.hpp"
#include "textures.hpp"

piece::piece(chessPieces piece, chessColor color):m_piece{piece}, m_color{color}
{
    textures::get_textures()->set_textPiece(this);
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

void piece::set_spritePosition(sf::Vector2f position)
{
	m_sprite.setPosition(position);
}

void piece::set_spritePosition(int x, int y)
{
	set_spritePosition(sf::Vector2f(x, y));
}

void piece::set_spriteScale(sf::Vector2f scale)
{
	m_sprite.setScale(scale);
}

void piece::set_spriteScale(int x, int y)
{
	set_spriteScale(sf::Vector2f(x, y));
}