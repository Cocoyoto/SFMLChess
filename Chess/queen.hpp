#pragma once

#include "piece.hpp"

class Queen :
    public Piece
{
public:
    Queen() = delete;
    Queen(const chessColor color, const sf::Vector2u position);

    ~Queen();

    chessPieces getChessPiece() const noexcept override;
    unsigned int getPoints() const noexcept override;
    char getFenPiece() const noexcept override;

private:
    void updatePossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept override;
};

