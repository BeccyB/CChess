#pragma once

#include <string>

namespace chess
{


    enum class PieceType
    {
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING,
    };

    std::string to_string(const PieceType type);

}