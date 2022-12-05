#include "board.hpp"

board::board() :m_board{ BOARD_SIZE, (vector<piece*>(BOARD_SIZE,nullptr)) },
m_window{sf::VideoMode(WINDOW_SIZE,WINDOW_SIZE) , "CHESS BOARD"},
m_colorBoard{ BOARD_SIZE , vector<bool>(BOARD_SIZE,false) }
{
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        for (int x = 0; x < BOARD_SIZE; ++x)
        {
            m_colorBoard[x][y] = !((x + y) % 2);
        }
    }
    m_font.loadFromFile(FONT_NAME);
    initPieces();
}

board::~board()
{
    //destroy the vertex of the board
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        for (int x = 0; x < BOARD_SIZE; ++x)
        {
            if (m_board[x][y])
            {
                delete m_board[x][y];
            }
        }
    }
}

void board::initPieces()
{
    const int penultimateRow = BOARD_SIZE - 2;

    const int penultimateRowLocation = MARGIN + SQUARE_SIZE * 2;
    const int secondRowLocation = MARGIN + SQUARE_SIZE * (BOARD_SIZE - 2);
    const int firstRowLocation = 0;
    const int lastRowLocation = 0;

    for (int x = 0; x < BOARD_SIZE; ++x)
    {
        m_board[x][penultimateRow] = new piece(pawn,black);
        m_board[x][penultimateRow]->set_spriteScale(scalePiece, scalePiece);
        m_board[x][penultimateRow]->set_spritePosition (MARGIN + SQUARE_SIZE * x + pieceGap, penultimateRowLocation);

        m_board[x][1] = new piece(pawn, white);
        m_board[x][1]->set_spriteScale(scalePiece, scalePiece);
        m_board[x][1]->set_spritePosition(MARGIN + SQUARE_SIZE * x + pieceGap, secondRowLocation);

    }
    
}

void board::draw()
{
    m_window.clear(DARK);

    //drawing background
    drawChessOutline();
    drawChessBoard();

    //writting coordonates
    drawCoordinates();

    //drawing pieces
    drawPieces();

    m_window.display();
}

void board::drawChessOutline()
{
    //drawing the outline
    sf::RectangleShape boardOutline(sf::Vector2f(FULLBOARD_SIZE, FULLBOARD_SIZE));
    boardOutline.setPosition(MARGIN, MARGIN);
    boardOutline.setOutlineThickness(5);
    boardOutline.setOutlineColor(OUTLINE);
    boardOutline.setFillColor(sf::Color::Transparent);
    m_window.draw(boardOutline);
}

void board::drawChessBoard()
{
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        for (int x = 0; x < BOARD_SIZE; ++x)
        {
            sf::RectangleShape boardSquare(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
            boardSquare.setPosition(MARGIN + x * SQUARE_SIZE, MARGIN + y * SQUARE_SIZE);
            if (m_colorBoard[x][y])
            {
                boardSquare.setFillColor(BRIGHT);
            }
            else
            {
                boardSquare.setFillColor(DARK);
            }
            m_window.draw(boardSquare);
        }
    }
}

void board::drawCoordinates()
{
    sf::Text coordonate;
    coordonate.setFont(m_font);
    coordonate.setCharacterSize(SQUARE_SIZE / 3);
    coordonate.setFillColor(BRIGHT);
    coordonate.setStyle(sf::Text::Bold);

    const double valueCalc = MARGIN + (SQUARE_SIZE / 2) - (coordonate.getCharacterSize() / 2);
    const double valueBorderBot = WINDOW_SIZE - MARGIN;
    const double valueBorderLeft = MARGIN - coordonate.getCharacterSize();
    char files = 'A';

    for (int x = 0; x < BOARD_SIZE; ++x, ++files)
    {
        coordonate.setString(files);
        coordonate.setPosition(valueCalc + (x * SQUARE_SIZE), valueBorderBot);
        m_window.draw(coordonate);
    }
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        coordonate.setString(std::to_string(BOARD_SIZE - y));
        coordonate.setPosition(valueBorderLeft, valueCalc + (y * SQUARE_SIZE));
        m_window.draw(coordonate);
    }
}

void board::drawPieces()
{
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        for (int x = 0; x < BOARD_SIZE; ++x)
        {
            if (m_board[x][y])
            {
                m_window.draw(m_board[x][y]->get_sprite());
            }
        }
    }
}