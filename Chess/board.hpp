#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "game.typedef.hpp"

class Piece;

using std::vector;

inline void indexToName(const sf::Vector2u& position, std::string& name) noexcept
{
	name = "";
	name += 'A' + position.x;
	name += '1' + position.y;
}

inline void nameToIndex(const std::string& name, sf::Vector2u& position) noexcept
{
	position.x = name[0] - 'A';
	position.y = name[1] - '1';
}

inline Piece* getPiece(const sf::Vector2u& position, std::vector<std::vector<Piece*>>& board) noexcept
{
	return board[position.x][position.y];
}

inline Piece* getPiece(const std::string& name, std::vector<std::vector<Piece*>>& board) noexcept
{
	sf::Vector2u position;
	nameToIndex(name, position);
	return getPiece(position, board);
}

class Board
{
public :
	Board(const BoardConfig& config);

	~Board();

	unsigned int getSize() const noexcept;
	const std::vector<std::vector<Piece*>>& getPieces() const noexcept;

	void FENreader(const std::string& fen) noexcept;
	std::string FEN() const noexcept;
private:	
	BoardConfig m_config;

	std::vector<std::vector<Piece*>> m_board;//[0][0] = A1
};