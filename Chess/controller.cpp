#include "controller.hpp"

Controller::Controller(Renderer* rend, Board* board):
	m_rend(rend),
	m_board(board)
{

}

Controller::~Controller()
{

}

void Controller::update()
{
	sf::Event event;

	while (m_rend->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_rend->closeWindow();
				break;
			}
			/* else if (event.type == sf::Event::Resized)
			{
				waitInput = false;
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				m_board.clic(event.mouseButton.x, event.mouseButton.y, WHITEToPlay);
				waitInput = false;
			} */
		}
}