#pragma once

#include <SFML/Graphics.hpp>

class Textures
{
public:
	Textures(Textures& copy) = delete;
	void operator= (const Textures& copy) = delete;

	// static Textures* get_textures();

	// void set_textPiece(Piece* chessPiece) const;
	
private:
	Textures();

	// sf::Texture m_piecesTex;
};