#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <forward_list>

enum chessPieces { PAWN, KNIGHT, ROOK, BISHOP, QUEEN, KING };
enum chessColor { BLACK, WHITE, COUNT };

inline chessColor nextColor(chessColor color)
{
	return (chessColor)(((int)color + 1) % COUNT);
}

class King;

class Piece
{
public:
	Piece() = delete;
	Piece(const chessColor color, const sf::Vector2u position);

	~Piece();

	virtual chessPieces getChessPiece() const noexcept = 0;
	virtual unsigned int getPoints() const noexcept = 0;
	virtual char getFenPiece() const noexcept = 0;
	virtual std::vector<sf::Vector2u>& getPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept;//TODO add particular rules (castle, en passant, promotion)
	virtual bool doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept = 0;

	chessColor getPieceColor() const noexcept;
	const sf::Vector2u& getPosition() const noexcept;
	std::string getStringPosition() const noexcept;
	King* getKing() const noexcept;
	void clearMoves() noexcept;

	void setPosition(const sf::Vector2u& position) noexcept;
	void setKing(King* king) noexcept;

	bool addMove(std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, std::vector<sf::Vector2u>& possibleMoves, sf::Vector2u move);

	static bool isMoveLegal(const std::vector<std::forward_list<Piece*>>& pieces, King* king, const std::vector<std::vector<Piece*>>& board, const Piece* captured = nullptr) noexcept;

private:
	virtual void updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept = 0;


	const chessColor m_color;

protected:
	sf::Vector2u m_position;//0,0 = A1
	bool m_isPossibleMooveActualized;
	std::vector<sf::Vector2u> m_possibleMoves;
	King* m_king;
};