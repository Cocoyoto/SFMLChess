#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "game.typedef.hpp"
#include "board.hpp"
#include "resourceHolder.hpp"

const std::string FONT_NAME = "rainyhearts.ttf";
const unsigned int MARGIN = 50;


struct BoardColors {
	sf::Color dark;
	sf::Color bright;
	sf::Color outline;
	sf::Color move_preview;
	sf::Color background;
	sf::Color selectedBackground;
	sf::Color check;
};

class Renderer
{
public:
	Renderer(const RendererConfig& config);

	void changeConfig(const RendererConfig& config) noexcept;
	void changeBoard(Board* board) noexcept;

	void draw() const;
	void draw(const sf::Vector2u& positionFocused, const std::vector<sf::Vector2u>& possiblesMooves) const;

	bool pollEvent(sf::Event& event);

	void openWindow(const RendererConfig& config);
	void closeWindow();
	bool hasWindow() const;

	void piecesEdit() noexcept; //each pieceEdit need to call it to update pieces vertex array

	std::string getSquareName(int mouseX, int mouseY) const noexcept;
	sf::Vector2u getSquarePosition(int mouseX, int mouseY) const noexcept;

private :
	void drawCoordinates() const;
	void drawPossiblesMooves(const std::vector<sf::Vector2u>& possiblesMooves, const sf::Vector2u& position) const;

	void createBoardRend() noexcept;
	void createPiecesRend() noexcept;
	void appendOutline(float x, float y, float width, float height, sf::Color color, float thickness, sf::VertexArray& VertexArray) const noexcept;
	void appendSquare(float x, float y, float width, float height, sf::Color color, sf::VertexArray& VertexArray) const noexcept;
	void appendSquare(float x, float y, float width, float height, sf::VertexArray& VertexArray) const noexcept;

	std::unique_ptr<sf::RenderWindow> m_window;
	Board* m_board;
	unsigned int m_margin;
	float m_fullboardSize;
	float m_squareSize;
	sf::VertexArray m_boardRend;
	sf::VertexArray m_piecesRend;
	sf::Font m_font;
	BoardColors m_colors;
	ResourceHolder<std::string, sf::Texture> m_resourcesHolder;
};

