#pragma once

#include <SFML/Graphics.hpp>

enum chessPieces { PAWN, KNIGHT, ROOK, BISHOP, KING, QUEEN };
enum chessColor { BLACK, WHITE };

// const int Y_PIECE_GAP = 0;

// extern const double SQUARE_SIZE;

// const int SCALE_PIECE = SQUARE_SIZE / 32;
// const int X_PIECE_GAP = (SQUARE_SIZE - (16 * SCALE_PIECE * 1.0)) / 2;

class Piece
{
public:
	Piece() = delete;
	Piece(const chessColor color, const sf::Vector2u position);

	~Piece();

	virtual chessPieces getChessPiece() const noexcept = 0;
	virtual unsigned int getPoints() const noexcept = 0;
	virtual char getFenPiece() const noexcept = 0;

	chessColor getPieceColor() const noexcept;
	const sf::Vector2u getPosition() const noexcept;


	/* chessPieces get_piece() const;
	chessColor get_color() const;
	sf::Sprite& get_sprite();

	void set_piece(chessPieces chesspiece);

	void moove_piece(int x, int y, vector<vector<Piece*>> board);

	const vector <vector<int>>& get_possibleMooves() const;
	void set_possibleMooves(vector<vector<Piece*>> board); */

private:
	/* void set_spritePosition(sf::Vector2f position);
	void set_spritePosition(int x, int y);
	void set_spriteScale(sf::Vector2f scale);
	void set_spriteScale(int x, int y); */

	const chessColor m_color;
	sf::Vector2u m_position;//0,0 = A1
	//chessPieces m_piece;
	// sf::Sprite m_sprite;
	// bool m_firstMoove;

	// vector <vector<int>> m_possibleMooves;
};