#include "game.hpp"

game::game()
{

}

void game::play()
{
	bool playing = true;
	while (playing)
	{
		m_board.draw();
		sf::sleep(sf::seconds(10));
	}
}