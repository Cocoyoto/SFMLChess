#pragma once

#include <SFML/Graphics.hpp>

enum chessPieces { pawn, knight, rook, bishop, queen, king };
enum chessColor { white, black };

class piece
{
public:
	piece() = delete;
	piece(chessPieces piece, chessColor color);

	chessPieces get_piece() const;
	chessColor get_color() const;
	sf::Sprite& get_sprite();

	void set_piece(chessPieces chesspiece);

	void set_spritePosition(sf::Vector2f position);
	void set_spritePosition(int x, int y);
	void set_spriteScale(sf::Vector2f scale);
	void set_spriteScale(int x, int y);

private:
	const chessColor m_color;
	chessPieces m_piece;	
	sf::Sprite m_sprite;
};