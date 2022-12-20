#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>

#include "game.typedef.hpp"

class Piece;

using std::unordered_map;

class Board
{
public :
	Board(const BoardConfig& config);

	~Board();

	unsigned int getSize() const noexcept;
	const unordered_map<std::string, std::unique_ptr<Piece>>& getPieces() const noexcept;

	void FENreader(const std::string& fen) noexcept;
	std::string FEN() const noexcept;
private:	
	BoardConfig m_config;

	unordered_map<std::string, std::unique_ptr<Piece>> m_board;
};