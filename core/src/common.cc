#include "chess/common.h"

namespace chess
{

    std::string to_string(const Color color)
    {
        switch (color)
        {
        case Color::WHITE:
            return "W";
        case Color::BLACK:
            return "B";
        default:
            return "";
        }
    }

    std::string to_string(const PieceType type)
    {
        switch (type)
        {
        case PieceType::PAWN:
            return "P";
        default:
            return "";
        }
    }

}
