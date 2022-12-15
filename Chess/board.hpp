#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "game.typedef.hpp"

class Piece;

using std::vector;


//enum files { A, B, C, D, E, F, G, H };

class Board
{
public :
	Board(const BoardConfig& config);

	~Board();

	void FENreader(std::string fen);
	unsigned int getSize() const;
	
	//void clic(const int x, const int y, const bool WhiteToPlay);

private:
	
	// void initPieces();
	
	BoardConfig m_config;

	//vector<vector<Piece*>> m_board;//[A][8] == [0][0]
	//vector<vector<bool>> m_colorBoard;//true for WHITE , false for BLACK
	// Piece* m_focusedPiece;
};