#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "game.typedef.hpp"

class Piece;

using std::unordered_map;

class Board
{
public :
	Board(const BoardConfig& config);

	~Board();

	void FENreader(const std::string& fen);
	std::string FEN() const noexcept;
	unsigned int getSize() const;

private:
	
	// void initPieces();
	
	BoardConfig m_config;

	unordered_map<std::string, Piece*> m_board;
};