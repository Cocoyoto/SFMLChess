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
    m_board { config.board_size, std::vector<Piece*>(config.board_size, nullptr) },
    m_pieces { chessColor::COUNT },
    m_kings { chessColor::COUNT, nullptr }
{
}

Board::~Board()
{
    for (int i = 0; i < m_pieces.size(); ++i)
    {
        for (Piece* p : m_pieces[i])
        {
			delete p;
		}
	}
}

unsigned int Board::getSize() const noexcept
{
    return m_config.board_size;
}

const std::vector<std::vector<Piece*>>& Board::getBoard() const noexcept
{
    return m_board;
}

const std::vector<std::forward_list<Piece*>>& Board::getPieces() const noexcept
{
    return m_pieces;
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

bool Board::movePiece(Piece* piece, const sf::Vector2u& position) noexcept
{
    int points = 0;
    sf::Vector2u piecePos = piece->getPosition();

    if (!piece->setPosition(position))
    {
		return false;
	}

    m_board[piecePos.x][piecePos.y] = nullptr;

    Piece* capture = m_board[position.x][position.y];

    if (capture)
    {
        points = capture->getPoints();
        delete capture;
    }

    m_board[position.x][position.y] = piece;

    for (int i = 0; i < m_pieces.size(); ++i)
    {
        auto it = m_pieces[i].begin();
        while (it != m_pieces[i].end())
        {
            if (*it == capture)
            {
                auto itCapture = it++;
				m_pieces[i].remove(*itCapture);
			}
            else
            {
				(*it)->clearMoves();
				++it;
			}
		}
    }

    m_kings[nextColor(piece->getPieceColor())]->updateCheck(m_pieces, m_board);

    return true;
    //return points;
}

unsigned int Board::isCheckMate(const chessColor& colorToPlay) noexcept
{
    return m_kings[colorToPlay]->isCheckMate(m_board, m_pieces);
}

chessColor Board::FENreader(const std::string& fen) noexcept
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
            m_pieces[BLACK].push_front(m_board[files][row]);
            files++;
			break;
        case 'r':
            m_board[files][row] = new Rook(BLACK, sf::Vector2u(files, row));
            m_pieces[BLACK].push_front(m_board[files][row]);
            files++;
            break;
        case 'n':
            m_board[files][row] = new Knight(BLACK, sf::Vector2u(files, row));
            m_pieces[BLACK].push_front(m_board[files][row]);
            files++;
            break;
        case 'b':
            m_board[files][row] = new Bishop(BLACK, sf::Vector2u(files, row));
            m_pieces[BLACK].push_front(m_board[files][row]);
            files++;
            break;
        case 'q':
            m_board[files][row] = new Queen(BLACK, sf::Vector2u(files, row));
            m_pieces[BLACK].push_front(m_board[files][row]);
            files++;
            break;
        case 'k':
            m_kings[BLACK] = new King(BLACK, sf::Vector2u(files, row));
            m_pieces[BLACK].push_front(m_kings[BLACK]);
            m_board[files][row] = m_kings[BLACK];
            files++;
            break;
        case 'P':
            m_board[files][row] = new Pawn(WHITE, sf::Vector2u(files, row));
            m_pieces[WHITE].push_front(m_board[files][row]);
            files++;
            break;
        case 'R':
            m_board[files][row] = new Rook(WHITE, sf::Vector2u(files, row));
            m_pieces[WHITE].push_front(m_board[files][row]);
            files++;
            break;
        case 'N':
            m_board[files][row] = new Knight(WHITE, sf::Vector2u(files, row));
            m_pieces[WHITE].push_front(m_board[files][row]);
            files++;
            break;
        case 'B':
            m_board[files][row] = new Bishop(WHITE, sf::Vector2u(files, row));
            m_pieces[WHITE].push_front(m_board[files][row]);
            files++;
            break;
        case 'Q':
            m_board[files][row] = new Queen(WHITE, sf::Vector2u(files, row));
            m_pieces[WHITE].push_front(m_board[files][row]);
            files++;
            break;
        case 'K':
            m_kings[WHITE] = new King(WHITE, sf::Vector2u(files, row));
            m_pieces[WHITE].push_front(m_kings[WHITE]);
            m_board[files][row] = m_kings[WHITE];
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
        //TODO return color to play
    }

    for (int i = 0; i < m_pieces.size(); ++i)
    {
        for (Piece* p : m_pieces[i])
        {
            p->setKing(m_kings[i]);
        }
    }

    chessColor colorToPlay = chessColor::WHITE;
    m_kings[colorToPlay]->updateCheck(m_pieces, m_board);

    return colorToPlay;
}

std::string Board::FEN() const noexcept
{
    return "";
}