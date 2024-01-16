#pragma once

#include "piece.hpp"

class Pawn :
    public Piece
{
public :
    Pawn() = delete;
    Pawn(const chessColor color, const sf::Vector2u position);

    ~Pawn();

    chessPieces getChessPiece() const noexcept override;
    unsigned int getPoints() const noexcept override;
    char getFenPiece() const noexcept override;
    virtual bool doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept override;

    static bool pawnCheck(const sf::Vector2u& piecePosition, const King* king) noexcept;
    static void pawnPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, Piece* piece, std::vector<sf::Vector2u>& possibleMoves) noexcept;

private:
    void updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept override;

    bool m_hasMoved2Squares;
};

