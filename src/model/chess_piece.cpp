#include "model/chess_piece.h"

namespace model {

    std::string to_string(Colour colour) {
        if (colour == Colour::WHITE) {
            return "White";
        }
        return "Black";
    }
} // namespace model