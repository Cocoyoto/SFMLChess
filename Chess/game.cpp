#include "game.hpp"

Game::Game():
	m_board { }
{

}

//to do : possibility to drag and drop pieces
void Game::play()
{
	sf::Event event;
	bool playing = true;
	bool waitInput = false;
	bool WHITEToPlay = true;
	Piece* pieceFocus = nullptr;

	while (playing && m_window.isOpen())
	{
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
			else if (event.type == sf::Event::Resized)
			{
				waitInput = false;
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				m_board.clic(event.mouseButton.x, event.mouseButton.y, WHITEToPlay);
				waitInput = false;
			}
		}
		
		if (!waitInput)
		{
			m_board.draw(m_window);
			waitInput = true;
		}
	}
}