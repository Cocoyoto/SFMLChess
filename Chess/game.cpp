#include "game.hpp"

Game::Game(const GameConfig& config):
	m_running(false),
	m_board(config.board),
	m_rend(config.renderer, &m_board),
	m_contr(&m_rend, &m_board)
{

}

bool Game::isRunning() const {
	return m_running && m_rend.hasWindow();
}

//to do : possibility to drag and drop pieces
void Game::play()
{
	m_running = true;

	bool waitInput = false;
	// bool WHITEToPlay = true;
	// Piece* pieceFocus = nullptr;

	while (isRunning())
	{
		waitInput= m_contr.update();

		if(m_rend.hasWindow() && !waitInput)
		{
			m_rend.draw();
		}
		
		/* if (!waitInput)
		{
			m_board.draw(m_window);
			waitInput = true;
		} */
	}
}