#pragma once
#include <SFML/Graphics.hpp>

struct RendererConfig {
	unsigned int window_size;
	std::string window_name;
};

struct BoardConfig {
	unsigned int board_size;
};

struct GameConfig {
	RendererConfig renderer;
	BoardConfig board;
};

/*

Utilisation :

GameConfig config {
	// renderer
	{
		// ...
	},
	// board
	{
		// ...
	}
};

Game g(config);

dans le constructeur de Game :

m_renderer.loadFromConfig(config.renderer);
m_board.loadFromConfig(config.board);

*/