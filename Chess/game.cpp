#include "game.hpp"

Game::Game(const GameConfig& config):
	m_running(false),
	m_board(config.board),
	m_rend(config.renderer),
	m_contr(&m_rend, &m_board)
{
	m_rend.changeBoard(&m_board);
}

bool Game::isRunning() const {
	return m_running && m_rend.hasWindow();
}

void Game::play()
{
	if (!m_rend.hasWindow())
	{
		return;
	}

	m_running = true;
	bool waitInput = false;

	m_rend.draw();

	while (isRunning())
	{
		waitInput = m_contr.update();
	}
}

void Game::newGame() noexcept
{
	//m_contr.setColorToPlay(m_board.FENreader("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
	m_contr.setColorToPlay(m_board.FENreader("3N4/4B1P1/5Kpp/1BPp3b/1p1k3q/2b1r2n/1p1ppQ2/8"));
	m_rend.piecesEdit();
}