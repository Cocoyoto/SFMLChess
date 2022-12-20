#pragma once

#include "piece.hpp"

class Rook :
    public Piece
{
public:
    Rook() = delete;
    Rook(const chessColor color, const sf::Vector2u position);

    ~Rook();

    chessPieces getChessPiece() const noexcept override;
    unsigned int getPoints() const noexcept override;
    char getFenPiece() const noexcept override;
};

