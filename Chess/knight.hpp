#pragma once

#include "piece.hpp"

class Knight :
    public Piece
{
public:
    Knight() = delete;
    Knight(const chessColor color, const sf::Vector2u position);

    ~Knight();

    chessPieces getChessPiece() const noexcept override;
    unsigned int getPoints() const noexcept override;
    char getFenPiece() const noexcept override;

private:
    void updatePossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept override;
};


