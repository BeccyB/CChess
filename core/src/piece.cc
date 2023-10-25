#include "chess/piece.h"

namespace chess::game
{

    std::string to_string(const Piece &pice)
    {
        return chess::to_string(pice.color_) + chess::to_string(pice.type_);
    }

}