#pragma once

#include <SFML/Graphics.hpp>

enum chessPieces { PAWN, KNIGHT, ROOK, BISHOP, QUEEN, KING };
enum chessColor { BLACK, WHITE };

class Piece
{
public:
	Piece() = delete;
	Piece(const chessColor color, const sf::Vector2u position);

	~Piece();

	virtual chessPieces getChessPiece() const noexcept = 0;
	virtual unsigned int getPoints() const noexcept = 0;
	virtual char getFenPiece() const noexcept = 0;
	//virtual std::vector<sf::Vector2u> getPossibleMoves(const std::vector<std::vector<Piece*>>& board) const noexcept = 0;

	chessColor getPieceColor() const noexcept;
	const sf::Vector2u& getPosition() const noexcept;
	std::string getStringPosition() const noexcept;


	/* 
	void moove_piece(int x, int y, vector<vector<Piece*>> board);

	const vector <vector<int>>& get_possibleMooves() const;
	void set_possibleMooves(vector<vector<Piece*>> board); */

private:
	const chessColor m_color;
	sf::Vector2u m_position;//0,0 = A1
	// bool m_firstMoove;

	//virtual std::vector<sf::Vector2u> m_possibleMooves;
};