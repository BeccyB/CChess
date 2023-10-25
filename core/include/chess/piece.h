#pragma once

#include "chess/common.h"

namespace chess::game
{
    struct Piece
    {
        PieceType type_;
        Color color_;
    };

    std::string to_string(const Piece &pice);
}