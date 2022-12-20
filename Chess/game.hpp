#pragma once

#include <SFML/Graphics.hpp>

#include "board.hpp"
#include "renderer.hpp"
#include "controller.hpp"


class Game
{
public:
	Game(const GameConfig& config);
	
	void play();

	void newGame() noexcept;

	bool isRunning() const;

private:
	bool m_running;

	Board m_board;
	Renderer m_rend;
	Controller m_contr;
};