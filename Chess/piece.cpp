#include "piece.hpp"
#include "textures.hpp"
#include "board.hpp"

Piece::Piece(chessPieces piece, chessColor color, int x, int y):
	m_color { color },
	m_rows { y },
	m_files { x },
	m_piece { piece },
	m_possibleMooves { vector<vector<int>> (2 , vector <int> (0,0))}
{

    Textures::get_textures()->set_textPiece(this);
	m_sprite.setScale(sf::Vector2f(SCALE_PIECE, SCALE_PIECE));
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
	if (m_piece == pawn)
	{
		m_piece = chesspiece;
		Textures::get_textures()->set_textPiece(this);
	}
}

//check if the moove is possible ? (in array)
void Piece::moove_piece(int x, int y, vector<vector<Piece*>> board)
{
	m_files = x;
	m_rows = y;
	set_spritePosition(x, y);
	set_possibleMooves(board);
}

const vector <vector<int>>& Piece::get_possibleMooves() const
{
	return m_possibleMooves;
}

void Piece::set_possibleMooves(vector<vector<Piece*>> board)
{
	
}

void Piece::set_spritePosition(sf::Vector2f position)
{
	m_sprite.setPosition(sf::Vector2f(MARGIN + SQUARE_SIZE * position.x + PIECE_GAP, (MARGIN + SQUARE_SIZE * position.y) - Y_PIECE_GAP));
}

void Piece::set_spritePosition(int x, int y)
{
	m_sprite.setPosition(sf::Vector2f(MARGIN + SQUARE_SIZE * x + PIECE_GAP, (MARGIN + SQUARE_SIZE * y) - Y_PIECE_GAP));
}

void Piece::set_spriteScale(sf::Vector2f scale)
{
	m_sprite.setScale(scale);
}

void Piece::set_spriteScale(int x, int y)
{
	set_spriteScale(sf::Vector2f(x, y));
}
