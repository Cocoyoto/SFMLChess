#include "textures.hpp"

Textures* Textures::get_textures()
{
	static Textures textures_;
	return &textures_;
}

Textures::Textures()
{
	std::string path = "./assets/";
	m_piecesTex.loadFromFile(path + "chess_pieces.png");
}

void Textures::set_textPiece(Piece* chessPiece) const
{
	chessPiece->get_sprite().setTexture(m_piecesTex);

	const int x = chessPiece->get_piece() * 16;
	const int y = chessPiece->get_color() * 32;

	chessPiece->get_sprite().setTextureRect(sf::IntRect(x, y, 16, 32));
}