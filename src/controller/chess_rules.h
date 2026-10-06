#pragma once

#include "model/board.h"
#include "model/chess_game.h"
#include "model/chess_piece.h"
#include "model/game_move.h"

namespace rules {

    /*

    - draw situation (must be checked before user selects piece)

    - is it currently a check or check mate situation?
        (check could also be checked later but check mate must be done before
        user selects field! -> rather do this after a move was made?)

    - check if move is valid:
        - is piece of current player
        - is the field free:
            - No, piece wants to take other piece
            - Yes
        - can the piece reache that field?
        - if field not freen, can it take the piece?
        -

    */

    model::ChessMoveStatus
    determine_game_move_validity(const model::Board &board,
                                 const model::GameMove next_move);

    bool is_colour_check_mate(const model::Board &board, model::Colour colour);

    bool is_colour_in_check_situation(const model::Board &board,
                                      model::Colour colour);

    bool is_automatic_patt(const model::ChessGame game);

} // namespace rules