#pragma once

#include "piece.hpp"

class Bishop :
    public Piece
{
public:
    Bishop() = delete;
    Bishop(const chessColor color, const sf::Vector2u position);

    ~Bishop();

    chessPieces getChessPiece() const noexcept;
    unsigned int getPoints() const noexcept;
    char getFenPiece() const noexcept override;

private :
    void updatePossibleMoves(const std::vector<std::vector<Piece*>>& board) noexcept override;
};

