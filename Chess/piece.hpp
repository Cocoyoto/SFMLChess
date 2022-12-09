#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using std::vector;

enum chessPieces { pawn, knight, rook, bishop, king, queen };
enum chessColor { black, white };

const int Y_PIECE_GAP = 0;

extern const double SQUARE_SIZE;

const int SCALE_PIECE = SQUARE_SIZE / 32;
const int X_PIECE_GAP = (SQUARE_SIZE - (16 * SCALE_PIECE * 1.0)) / 2;

class Piece
{
public:
	Piece() = delete;
	Piece(chessPieces piece, chessColor color, int files, int rows);

	chessPieces get_piece() const;
	chessColor get_color() const;
	sf::Sprite& get_sprite();

	void set_piece(chessPieces chesspiece);

	void moove_piece(int x, int y, vector<vector<Piece*>> board);

	const vector <vector<int>>& get_possibleMooves() const;
	void set_possibleMooves(vector<vector<Piece*>> board);

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
	bool m_firstMoove;

	vector <vector<int>> m_possibleMooves;
};