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
    virtual bool doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept override;

    static bool bishopCheck(const std::vector<std::vector<Piece*>>& board, const sf::Vector2u& piecePosition, const King* king) noexcept;
    static void bishopPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, Piece* piece, std::vector<sf::Vector2u>& possibleMoves) noexcept;

private :
    void updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept override;
};

