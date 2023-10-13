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
    m_board { config.board_size, std::vector<Piece*>(config.board_size, nullptr) }
{
}

Board::~Board()
{
    for (int i = 0; i < m_config.board_size; ++i)
    {
        for (int j = 0; j < m_config.board_size; ++j)
        {
            if (m_board[i][j])
            {
                delete m_board[i][j];
            }
		}
	}
}

unsigned int Board::getSize() const noexcept
{
    return m_config.board_size;
}

const std::vector<std::vector<Piece*>>& Board::getPieces() const noexcept
{
    return m_board;
}

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
    int row = m_config.board_size - 1;
    int files = 0;

    for (unsigned int i = 0; i < fen.size() && fen[i] != ' '; ++i)
    {
        char value = fen[i];
        switch (value)
        {
        case 'p':
            m_board[files][row] = new Pawn(BLACK, sf::Vector2u(files, row));
            files++;
			break;
        case 'r':
            m_board[files][row] = new Rook(BLACK, sf::Vector2u(files, row));
            files++;
            break;
        case 'n':
            m_board[files][row] = new Knight(BLACK, sf::Vector2u(files, row));
            files++;
            break;
        case 'b':
            m_board[files][row] = new Bishop(BLACK, sf::Vector2u(files, row));
            files++;
            break;
        case 'q':
            m_board[files][row] = new Queen(BLACK, sf::Vector2u(files, row));
            files++;
            break;
        case 'k':
            m_board[files][row] = new King(BLACK, sf::Vector2u(files, row));
            files++;
            break;
        case 'P':
            m_board[files][row] = new Pawn(WHITE, sf::Vector2u(files, row));
            files++;
            break;
        case 'R':
            m_board[files][row] = new Rook(WHITE, sf::Vector2u(files, row));
            files++;
            break;
        case 'N':
            m_board[files][row] = new Knight(WHITE, sf::Vector2u(files, row));
            files++;
            break;
        case 'B':
            m_board[files][row] = new Bishop(WHITE, sf::Vector2u(files, row));
            files++;
            break;
        case 'Q':
            m_board[files][row] = new Queen(WHITE, sf::Vector2u(files, row));
            files++;
            break;
        case 'K':
            m_board[files][row] = new King(WHITE, sf::Vector2u(files, row));
            files++;
            break;
        case '/':
            row--;
			files = 0;
			break;
        case ' ':
			break;
        default:
            files += value - '0';
            break;
        }

        //need to do last part of fen (after space)
    }
}

std::string Board::FEN() const noexcept
{
    return "";
}