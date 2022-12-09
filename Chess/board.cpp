#include "board.hpp"
#include "piece.hpp"
#include <iostream>

Board::Board() :
    m_board{ BOARD_SIZE, (vector<Piece*>(BOARD_SIZE,nullptr)) },
    m_colorBoard{ BOARD_SIZE , vector<bool>(BOARD_SIZE,false) },
    m_focusedPiece { nullptr }
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

Board::~Board()
{
    //destroy the vertex of the Board
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

void Board::initPieces()
{
    const int penultimateRow = BOARD_SIZE - 2;

    for (int x = A; x < BOARD_SIZE; ++x)
    {
        m_board[x][penultimateRow] = new Piece(pawn, white, x, penultimateRow);

        m_board[x][1] = new Piece(pawn, black, x, 1);

    }

    //pieces hard coded for the moment only if the size of the Board is 8 
    //to-do find a cleaner implemantation
    if (BOARD_SIZE == 8)
    {
        m_board[A][BOARD_SIZE - 1] = new Piece(rook, white, A, BOARD_SIZE - 1);
        m_board[A][0] = new Piece(rook, black, A, 0);

        m_board[H][BOARD_SIZE - 1] = new Piece(rook, white, H, BOARD_SIZE - 1);
        m_board[H][0] = new Piece(rook, black, H, 0);


        m_board[B][BOARD_SIZE - 1] = new Piece(knight, white, B, BOARD_SIZE - 1);
        m_board[B][0] = new Piece(knight, black, B, 0);

        m_board[G][BOARD_SIZE - 1] = new Piece(knight, white, G, BOARD_SIZE - 1);
        m_board[G][0] = new Piece(knight, black, G, 0);


        m_board[C][BOARD_SIZE - 1] = new Piece(bishop, white, C, BOARD_SIZE - 1);
        m_board[C][0] = new Piece(bishop, black, C, 0);

        m_board[F][BOARD_SIZE - 1] = new Piece(bishop, white, F, BOARD_SIZE - 1);
        m_board[F][0] = new Piece(bishop, black, F, 0);


        m_board[D][BOARD_SIZE - 1] = new Piece(king, white, D, BOARD_SIZE - 1);
        m_board[D][0] = new Piece(king, black, D, 0);

        m_board[E][BOARD_SIZE - 1] = new Piece(queen, white, E, BOARD_SIZE - 1);
        m_board[E][0] = new Piece(queen, black, E, 0);
    }
}

//to-do find a cleaner way to draw everything
void Board::draw(sf::RenderWindow& window)
{
    window.clear(DARK);

    //drawing background
    drawChessOutline(window);
    drawChessBoard(window);

    //writting coordonates
    drawCoordinates(window);

    //drawing pieces
    drawPieces(window);

    //drawing the possibles mooves of a focused piece
    drawPossiblesMooves(window);

    window.display();
}

void Board::drawChessOutline(sf::RenderWindow& window)
{
    //drawing the outline
    sf::RectangleShape boardOutline(sf::Vector2f(FULLBOARD_SIZE, FULLBOARD_SIZE));
    boardOutline.setPosition(MARGIN, MARGIN);
    boardOutline.setOutlineThickness(5);
    boardOutline.setOutlineColor(OUTLINE);
    boardOutline.setFillColor(sf::Color::Transparent);
    window.draw(boardOutline);
}

void Board::drawChessBoard(sf::RenderWindow& window)
{
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        for (int x = A; x < BOARD_SIZE; ++x)
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
            window.draw(boardSquare);
        }
    }
}

void Board::drawCoordinates(sf::RenderWindow& window)
{
    sf::Text coordonate;
    coordonate.setFont(m_font);
    coordonate.setCharacterSize(SQUARE_SIZE / 3);
    coordonate.setFillColor(BRIGHT);
    coordonate.setStyle(sf::Text::Bold);

    const double valueFiles = MARGIN + (SQUARE_SIZE / 2.0) -(coordonate.getCharacterSize() / 3);
    const double valueRows = MARGIN + (SQUARE_SIZE / 2.0) - (coordonate.getCharacterSize() / 2);
    const double valueBorderBot = WINDOW_SIZE - MARGIN;
    const double valueBorderLeft = MARGIN - coordonate.getCharacterSize();
    char files = 'A';

    for (int x = A; x < BOARD_SIZE; ++x, ++files)
    {
        coordonate.setString(files);
        coordonate.setPosition(valueFiles + (x * SQUARE_SIZE), valueBorderBot);
        window.draw(coordonate);
    }
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        coordonate.setString(std::to_string(BOARD_SIZE - y));
        coordonate.setPosition(valueBorderLeft, valueRows + (y * SQUARE_SIZE));
        window.draw(coordonate);
    }
}

void Board::drawPieces(sf::RenderWindow& window)
{
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        for (int x = A; x < BOARD_SIZE; ++x)
        {
            if (m_board[x][y])
            {
                window.draw(m_board[x][y]->get_sprite());
            }
        }
    }
}

//drawing possibles mooves of a focused piece
void Board::drawPossiblesMooves(sf::RenderWindow& window)
{
    if (m_focusedPiece)
    {
        vector <vector<int>> possiblesMooves = m_focusedPiece->get_possibleMooves();

        int radius = SQUARE_SIZE / 4;
        const double value = MARGIN + (SQUARE_SIZE / 2.0);
        for (int i = 0; i < possiblesMooves[0].size(); ++i)
        {
            sf::CircleShape circle;
            circle.setRadius(radius);
            circle.setPointCount(50);
            circle.setOrigin(radius, radius);
            circle.setPosition((possiblesMooves[0][i] * SQUARE_SIZE) + value, (BOARD_SIZE - possiblesMooves[1][i]) * SQUARE_SIZE);
            circle.setFillColor(MOOVE_PREVIEW);
            window.draw(circle);
        }
    }
}

void Board::FENreader(std::string fen)
{
    
}

void Board::clic(int x, int y, bool whiteToPlay)
{
    if (!m_focusedPiece)
    {
        const double maxSize = WINDOW_SIZE - MARGIN;
        if (x >= MARGIN && x <= maxSize && y >= MARGIN && y <= maxSize)
        {
            int clicX = (x - MARGIN) / SQUARE_SIZE;
            int clicY = (y - MARGIN) / SQUARE_SIZE;
            m_focusedPiece = m_board[clicX][clicY];
        }
    }
    else
    {
        //either the piece can moove there and so it moove , no matter that no more focused piece
        m_focusedPiece = nullptr;
    }
}