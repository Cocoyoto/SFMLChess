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
    virtual bool doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept override;

    static bool rookCheck(const std::vector<std::vector<Piece*>>& board, const sf::Vector2u& piecePosition, King* king) noexcept;
    static void rookPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, Piece* piece, std::vector<sf::Vector2u>& possibleMoves) noexcept;

private :
    void updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept override;
};

