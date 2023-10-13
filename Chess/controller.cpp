#include "controller.hpp"

Controller::Controller(Renderer* rend, Board* board):
	m_rend(rend),
	m_board(board),
	m_pieceFocused(false)
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
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				m_rend->clic(event.mouseButton.x, event.mouseButton.y);
			}
			//m_board.clic(event.mouseButton.x, event.mouseButton.y, WHITEToPlay);
		}
	}

	return eventHappen;
}