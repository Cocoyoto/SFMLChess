#include "queen.hpp"

Queen::Queen(const chessColor color, const sf::Vector2u position) :
	Piece(color, position)
{

}

Queen::~Queen()
{

}

chessPieces Queen::getChessPiece() const noexcept
{
	return QUEEN;
}

unsigned int Queen::getPoints() const noexcept
{
	return 1;
}

char Queen::getFenPiece() const noexcept
{
	if (getPieceColor() == WHITE)
	{
		return 'Q';
	}
	else
	{
		return 'q';
	}
}

void Queen::updatePossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept
{
	int x = m_position.x;
	int y = m_position.y;

	//down
	while (y > 0)
	{
		y--;
		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else if (board[x][y]->getPieceColor() != getPieceColor())
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
			break;
		}
		else
		{
			break;
		}
	}

	//up
	y = m_position.y;
	while (y < board.size()-1)
	{
		y++;
		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else if (board[x][y]->getPieceColor() != getPieceColor())
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
			break;
		}
		else
		{
			break;
		}
	}

	//left
	x = m_position.x;
	y = m_position.y;
	while (x > 0)
	{
		x--;
		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else if (board[x][y]->getPieceColor() != getPieceColor())
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
			break;
		}
		else
		{
			break;
		}
	}

	//right
	x = m_position.x;
	while (x < board.size() - 1)
	{
		x++;
		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else if (board[x][y]->getPieceColor() != getPieceColor())
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
			break;
		}
		else
		{
			break;
		}
	}

	//down right
	x = m_position.x;
	y = m_position.y;
	while (x > 0 && y > 0)
	{
		x--;
		y--;
		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else if (board[x][y]->getPieceColor() != getPieceColor())
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
			break;
		}
		else
		{
			break;
		}
	}

	//down right
	x = m_position.x;
	y = m_position.y;
	while (x < board.size() - 1 && y > 0)
	{
		x++;
		y--;
		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else if (board[x][y]->getPieceColor() != getPieceColor())
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
			break;
		}
		else
		{
			break;
		}
	}

	//up left
	x = m_position.x;
	y = m_position.y;
	while (x > 0 && y < board.size() - 1)
	{
		x--;
		y++;
		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else if (board[x][y]->getPieceColor() != getPieceColor())
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
			break;
		}
		else
		{
			break;
		}
	}

	//up right
	x = m_position.x;
	y = m_position.y;
	while (x < board.size()-1 && y < board.size() - 1)
	{
		x++;
		y++;
		if (board[x][y] == nullptr)
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
		}
		else if (board[x][y]->getPieceColor() != getPieceColor())
		{
			m_possibleMoves.push_back(sf::Vector2u(x, y));
			break;
		}
		else
		{
			break;
		}
	}
}