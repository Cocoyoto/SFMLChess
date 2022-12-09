#include "game.hpp"
#include <iostream>

Game::Game():
	m_board { },
	m_window { sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "CHESS BOARD" }
{

}

//to do : possibility to drag and drop pieces
void Game::play()
{
	sf::Event event;
	bool playing = true;
	bool waitInput = false;
	bool whiteToPlay = true;
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
				std::cerr << event.mouseButton.x << " " << event.mouseButton.y << std::endl;
				waitInput = false;
			}
		}
		
		if (!waitInput)
		{
			std::cerr << "drawing" << std::endl;
			m_board.draw(m_window);
			waitInput = true;
		}
	}
}