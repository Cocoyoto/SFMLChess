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

Piece* Board::getPiece(const sf::Vector2u& position) const noexcept
{
	return m_board[position.x][position.y];
}

Piece* Board::getPiece(const std::string& name) const noexcept
{
    sf::Vector2u position;
    nameToPosition(name, position);
    return getPiece(position);
}

Piece* Board::getPiece(const int& x, const int& y) const noexcept
{
    return m_board[x][y];
}

int Board::movePiece(Piece* piece, const sf::Vector2u& position) noexcept
{
    int points = 0;
    sf::Vector2u piecePos = piece->getPosition();
    m_board[piecePos.x][piecePos.y] = nullptr;

    Piece* capture = m_board[position.x][position.y];

    if (capture)
    {
        points = capture->getPoints();
        delete capture;
    }

    m_board[position.x][position.y] = piece;
    piece->setPosition(position);

    for (int i = 0; i < m_board.size(); ++i)
    {
        for (int j = 0; j < m_board.size(); ++j)
        {
            Piece* p = m_board[i][j];
            if (p)
            {
                p->clearMooves();
            }
        }
    }

    return points;
}

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

        //TODO last part of fen (after space)
    }
}

std::string Board::FEN() const noexcept
{
    return "";
}