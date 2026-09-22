#pragma once

#include <string>

namespace model {

    enum class Colour {
        WHITE,
        BLACK,
    };

    enum class PieceType {
        PAWN,
        QUEEN,
    };

    // What is a chess piece?
    // - has a type: queen, pawn, ...
    // - has a colour: black or white

    // - has abilities to move
    // - ...?

    // different representations:
    // - struct or class, pro type different class or one single
    // ChessPiece(colour, type)
    // - string WK (White King)
    // - pair of enum color,enum type (WHITE,KING)

    // Do we need to distingish between pieces of the same type?
    //

    // Possible implementations

    // - every chess piece is a different class
    // - additionally they have a common base class
    // - two enums

    // What is assosiated with a chess piece?
    class Piece {
        Colour colour;
        PieceType type;
    };

} // namespace model