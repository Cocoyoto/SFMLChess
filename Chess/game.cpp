#include "game.hpp"

Game::Game():
	m_board { },
	m_window { sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "CHESS BOARD" }
{

}

void Game::play()
{
	bool playing = true;
	while (playing)
	{
		m_board.draw(m_window);
		sf::sleep(sf::seconds(10));
	}
}