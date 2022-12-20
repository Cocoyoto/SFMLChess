#include "piece.hpp"
//#include "textures.hpp"

/*Piece::Piece(const chessPieces piece, const chessColor color, const sf::Vector2u position) :
	m_color { color },
	m_piece { piece },
	m_position { position }
	// m_possibleMooves { vector<vector<int>> (2 , vector <int> (0,0))},
	// m_firstMoove { true }
{

    // Textures::get_textures()->set_textPiece(this);
	// m_sprite.setScale(sf::Vector2f(SCALE_PIECE, SCALE_PIECE));
	// set_spritePosition(x, y);
}*/

Piece::Piece(const chessColor color, const sf::Vector2u position) :
	m_color{ color },
	m_position{ position }
{

}

Piece::~Piece()
{

}

chessColor Piece::getPieceColor() const noexcept
{
	return m_color;
}

const sf::Vector2u& Piece::getPosition() const noexcept
{
	return m_position;
}

std::string Piece::getStringPosition() const noexcept
{
	return (char)('A' + m_position.x) + std::to_string(m_position.y + 1);
}

/*
//check if the moove is possible ? (in array)
void Piece::moove_piece(int x, int y, vector<vector<Piece*>> board)
{
	m_firstMoove = false;
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
	
}*/