#pragma once

#include <string>

namespace chess
{
    /**
     * @brief Enum for color of pieces
     *
     */
    enum class Color
    {
        WHITE,
        BLACK
    };

    enum class PieceType
    {
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING,
    };

    std::string to_string(const Color color);

    std::string to_string(const PieceType type);

}