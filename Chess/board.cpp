#include "board.hpp"
#include "piece.hpp"

#include "pawn.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"

Board::Board(const BoardConfig& config):
    m_config { config },
    m_board {}
{
    // initPieces();
}

Board::~Board()
{

}

unsigned int Board::getSize() const noexcept
{
    return m_config.board_size;
}

const unordered_map<std::string, std::unique_ptr<Piece>>& Board::getPieces() const noexcept
{
    return m_board;
}

/* void Board::initPieces()
{
    const int penultimateRow = BOARD_SIZE - 2;

    for (int x = A; x < BOARD_SIZE; ++x)
    {
        m_board[x][penultimateRow] = new Piece(PAWN, WHITE, x, penultimateRow);

        m_board[x][1] = new Piece(PAWN, BLACK, x, 1);

    }

    //pieces hard coded for the moment only if the size of the Board is 8 
    //to-do find a cleaner implemantation
    if (BOARD_SIZE == 8)
    {
        m_board[A][BOARD_SIZE - 1] = new Piece(ROOK, WHITE, A, BOARD_SIZE - 1);
        m_board[A][0] = new Piece(ROOK, BLACK, A, 0);

        m_board[H][BOARD_SIZE - 1] = new Piece(ROOK, WHITE, H, BOARD_SIZE - 1);
        m_board[H][0] = new Piece(ROOK, BLACK, H, 0);


        m_board[B][BOARD_SIZE - 1] = new Piece(KNIGHT, WHITE, B, BOARD_SIZE - 1);
        m_board[B][0] = new Piece(KNIGHT, BLACK, B, 0);

        m_board[G][BOARD_SIZE - 1] = new Piece(KNIGHT, WHITE, G, BOARD_SIZE - 1);
        m_board[G][0] = new Piece(KNIGHT, BLACK, G, 0);


        m_board[C][BOARD_SIZE - 1] = new Piece(BISHOP, WHITE, C, BOARD_SIZE - 1);
        m_board[C][0] = new Piece(BISHOP, BLACK, C, 0);

        m_board[F][BOARD_SIZE - 1] = new Piece(BISHOP, WHITE, F, BOARD_SIZE - 1);
        m_board[F][0] = new Piece(BISHOP, BLACK, F, 0);


        m_board[D][BOARD_SIZE - 1] = new Piece(KING, WHITE, D, BOARD_SIZE - 1);
        m_board[D][0] = new Piece(KING, BLACK, D, 0);

        m_board[E][BOARD_SIZE - 1] = new Piece(QUEEN, WHITE, E, BOARD_SIZE - 1);
        m_board[E][0] = new Piece(QUEEN, BLACK, E, 0);
    }
} */

/*
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
} */

void Board::FENreader(const std::string& fen) noexcept
{
    int row = m_config.board_size;
    char files = 'A';

    for (unsigned int i = 0; i < fen.size() && fen[i] != ' '; ++i)
    {
        char value = fen[i];
        std::string key = files + std::to_string(row);
        switch (value)
        {
        case 'p':
            m_board.insert({ key, std::make_unique<Pawn> (BLACK, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case 'r':
            m_board.insert({ key, std::make_unique<Rook>(BLACK, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case 'n':
            m_board.insert({ key, std::make_unique<Knight>(BLACK, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case 'b':
            m_board.insert({ key, std::make_unique<Bishop>(BLACK, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case 'q':
            m_board.insert({ key, std::make_unique<Queen>(BLACK, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case 'k':
            m_board.insert({ key, std::make_unique<King>(BLACK, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case 'P':
            m_board.insert({ key, std::make_unique<Pawn>(WHITE, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case 'R':
            m_board.insert({ key, std::make_unique<Rook>(WHITE, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case 'N':
            m_board.insert({ key, std::make_unique<Knight>(WHITE, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case 'B':
            m_board.insert({ key, std::make_unique<Bishop>(WHITE, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case 'Q':
            m_board.insert({ key, std::make_unique<Queen>(WHITE, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case 'K':
            m_board.insert({ key, std::make_unique<King>(WHITE, sf::Vector2u(files++ - 'A', row - 1)) });
            break;
        case '/':
            row--;
            files = 'A';
            break;
        case ' ':
            break;
        default:
            files += value;
            break;
        }
    }

    //need to do last part of fen (after space)
}

std::string Board::FEN() const noexcept
{
    return "";
}