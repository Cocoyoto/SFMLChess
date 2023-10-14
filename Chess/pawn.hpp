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

private:
    void updatePossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept override;
};

