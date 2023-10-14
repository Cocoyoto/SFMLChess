#include "controller.hpp"
#include "piece.hpp"
#include <iostream>

Controller::Controller(Renderer* rend, Board* board) :
	Controller(rend, board, chessColor::WHITE)
{

}

Controller::Controller(Renderer* rend, Board* board, chessColor ColorToPlay) :
	m_rend(rend),
	m_board(board),
	m_pieceFocused(nullptr),
	m_colorToPlay(ColorToPlay)
{

}

Controller::~Controller()
{
	
}	

bool Controller::update()
{
	sf::Event event;

	bool eventHappen = false;
	while (m_rend->pollEvent(event))
	{
		eventHappen = true;
		if (event.type == sf::Event::Closed)
		{
			m_rend->closeWindow();
			break;
		}
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			handleClick(event);
		}
	}

	return eventHappen;
}

void Controller::handleClick(const sf::Event& event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2u square = m_rend->getSquarePosition(event.mouseButton.x, event.mouseButton.y);
		//TODO hilight square clicked if a piece is on it and possible mooves
		if (square.x == -1 || square.y == -1)
		{	
			m_rend->draw();
			return;
		}

		if (m_pieceFocused == nullptr)
		{
			Piece* piece = m_board->getPiece(square);
			if (piece && piece->getPieceColor() == m_colorToPlay)
			{
				m_pieceFocused = piece;
				m_rend->draw(m_pieceFocused->getPosition(), m_pieceFocused->getPossibleMoves(m_board->getPieces()));
				return;
			}
			else
			{
				m_rend->draw();
				return;
			}
		}
		else
		{
			Piece* pieceClicked = m_board->getPiece(square);

			if (pieceClicked != nullptr)
			{
				if (pieceClicked->getPieceColor() == m_pieceFocused->getPieceColor())
				{
					m_pieceFocused = pieceClicked;
					m_rend->draw(m_pieceFocused->getPosition(), m_pieceFocused->getPossibleMoves(m_board->getPieces()));
					return;
				}
			}

			std::vector<sf::Vector2u> possibleMoves = m_pieceFocused->getPossibleMoves(m_board->getPieces());

			for (int i = 0; i < possibleMoves.size(); ++i)
			{
				if (possibleMoves[i] == square)
				{
					m_board->movePiece(m_pieceFocused, square);
					m_rend->piecesEdit();
					m_rend->draw();
					m_colorToPlay = nextColor(m_colorToPlay);
					break;
				}
			}
			m_pieceFocused = nullptr;
			m_rend->draw();
		}
	}
	else if (event.mouseButton.button == sf::Mouse::Right)
	{
		//hilight square ?
		//m_rend->draw();
	}
}