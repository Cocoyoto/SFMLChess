#pragma once

#include <SFML/Graphics.hpp>

#include "piece.hpp"

class textures
{
public:
	textures(textures& copy) = delete;
	void operator= (const textures& copy) = delete;

	static textures* get_textures();

	void set_textPiece(piece* chessPiece) const;
	
private:
	textures();

	sf::Texture m_piecesTex;
};