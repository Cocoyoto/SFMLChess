#pragma once

#include <SFML/Graphics.hpp>

#include "board.hpp"

enum chessPieces { pawn, knight, rook, bishop, king, queen };
enum chessColor { black, white };

const int Y_PIECE_GAP = 0;

class Piece
{
public:
	Piece() = delete;
	Piece(chessPieces piece, chessColor color, int files, int rows);

	chessPieces get_piece() const;
	chessColor get_color() const;
	sf::Sprite& get_sprite();

	void set_piece(chessPieces chesspiece);

	void moove_piece(int x, int y);

	static int get_scalePiece();
	static int get_pieceGap();

private:
	void set_spritePosition(sf::Vector2f position);
	void set_spritePosition(int x, int y);
	void set_spriteScale(sf::Vector2f scale);
	void set_spriteScale(int x, int y);

	const chessColor m_color;
	int m_rows;
	int m_files;
	chessPieces m_piece;	
	sf::Sprite m_sprite;

	static const int m_scalePiece = SQUARE_SIZE / 32;
	static const int m_pieceGap = (SQUARE_SIZE - (16 * m_scalePiece * 1.0)) / 2;
};