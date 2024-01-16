#pragma once

#include <vector>
#include <forward_list>

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
    virtual bool doesCheck(const std::vector<std::vector<Piece*>>& board, King* king) const noexcept override;

    unsigned int isCheckMate(const std::vector<std::vector<Piece*>>& board, std::vector<std::forward_list<Piece*>>& pieces) noexcept;//0 = not checkmate, 1 = checkmate, 2 = stalemate
    static bool kingCheck(const sf::Vector2u& piecePosition, const King* king) noexcept;
    unsigned int isInCheck() const noexcept;//0 = not in check, 1 = single check, 2 = double check, only king can moove
    unsigned int updateCheck(const std::vector<std::forward_list<Piece*>>& pieces, const std::vector<std::vector<Piece*>>& board) noexcept;

    static void kingPossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces, King* piece, std::vector<sf::Vector2u>& possibleMoves) noexcept;

private:
    unsigned int m_isInCheck;//0 = not in check, 1 = single check, 2 = double check, only king can moove

    void updatePossibleMoves(const std::vector<std::vector<Piece*>>& board, const std::vector<std::forward_list<Piece*>>& pieces) noexcept override;
};