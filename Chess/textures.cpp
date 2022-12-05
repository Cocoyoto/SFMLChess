#include "textures.hpp"

textures* textures::get_textures()
{
	static textures textures_;
	return &textures_;
}

textures::textures()
{
	std::string path = "./assets/";
	m_blackPiecesTex.loadFromFile(path+ "BlackPieces-Sheet.png");
	m_whitePiecesTex.loadFromFile(path + "WhitePieces-Sheet.png");
}

void textures::set_textPiece(piece* chessPiece) const
{
	if (chessPiece->get_color() == white)
	{
		chessPiece->get_sprite().setTexture(m_whitePiecesTex);
	}
	else if (chessPiece->get_color() == black)
	{
		chessPiece->get_sprite().setTexture(m_blackPiecesTex);
	}

	const int x = chessPiece->get_piece() * 16;

	chessPiece->get_sprite().setTextureRect(sf::IntRect(x, 0, 16, 32));
}