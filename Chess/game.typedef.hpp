#pragma once
#include <SFML/Graphics.hpp>




const std::string FONT_NAME = "rainyhearts.ttf";

const sf::Color DARK(69, 76, 94, 255);
const sf::Color BRIGHT(230, 234, 215, 255);
const sf::Color OUTLINE = BRIGHT;
const sf::Color MOOVE_PREVIEW(55, 55, 55, 100);

struct RendererConfig {
	unsigned int margin;
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