#include "textures.hpp"

textures* textures::get_textures()
{
	static textures textures_;
	return &textures_;
}

textures::textures()
{
	std::string path = "./assets/";
	m_piecesTex.loadFromFile(path + "chess_pieces.png");
}

void textures::set_textPiece(piece* chessPiece) const
{
	chessPiece->get_sprite().setTexture(m_piecesTex);

	const int x = chessPiece->get_piece() * 16;
	const int y = chessPiece->get_color() * 32;

	chessPiece->get_sprite().setTextureRect(sf::IntRect(x, y, 16, 32));
}