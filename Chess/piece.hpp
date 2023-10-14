#pragma once

#include <SFML/Graphics.hpp>

enum chessPieces { PAWN, KNIGHT, ROOK, BISHOP, QUEEN, KING };
enum chessColor { BLACK, WHITE, COUNT };

inline chessColor nextColor(chessColor color)
{
	return (chessColor)(((int)color + 1) % COUNT);
}

class Piece
{
public:
	Piece() = delete;
	Piece(const chessColor color, const sf::Vector2u position);

	~Piece();

	virtual chessPieces getChessPiece() const noexcept = 0;
	virtual unsigned int getPoints() const noexcept = 0;
	virtual char getFenPiece() const noexcept = 0;
	virtual std::vector<sf::Vector2u>& getPossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept;//TODO add for each piece check if the king is in check and particular rules (castle, en passant, promotion)

	chessColor getPieceColor() const noexcept;
	const sf::Vector2u& getPosition() const noexcept;
	std::string getStringPosition() const noexcept;
	void clearMooves() noexcept;//TODO after each piece moove, clear the mooves of the other pieces

	void setPosition(const sf::Vector2u& position) noexcept;

private:
	virtual void updatePossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept = 0;

	const chessColor m_color;

protected:
	sf::Vector2u m_position;//0,0 = A1
	bool m_isPossibleMooveActualized;
	std::vector<sf::Vector2u> m_possibleMoves;
};