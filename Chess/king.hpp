#pragma once

#include "piece.hpp"

class King :
    public Piece
{
public:
    King() = delete;
    King(const chessColor color, const sf::Vector2u position);

    ~King();

    chessPieces getChessPiece() const noexcept override;
    unsigned int getPoints() const noexcept override;
    char getFenPiece() const noexcept override;
};