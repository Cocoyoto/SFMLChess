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
    virtual bool doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept override;

    static bool knightCheck(const std::vector<std::vector<Piece*>>& board, const sf::Vector2u& piecePosition, const King* king) noexcept;
    static void knightPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, Piece* piece, std::vector<sf::Vector2u>& possibleMoves) noexcept;

private:
    void updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept override;
};


