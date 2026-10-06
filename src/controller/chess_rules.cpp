#include "controller/chess_rules.h"

namespace rules {

    model::ChessMoveStatus
    determine_game_move_validity(const model::Board &board,
                                 const model::GameMove next_move) {

        if (!board.is_occupied(next_move.start())) {
            return model::ChessMoveStatus::NOT_OCCUPID;
        }

        if (board.is_occupied(next_move.destination())) {
            return model::ChessMoveStatus::OCCUPID;
        }

        // TODO: more checks here!!!!
        return model::ChessMoveStatus::VALID;
    }

    bool is_colour_check_mate(const model::Board &board, model::Colour colour) {
        return false;
    }

    bool is_colour_in_check_situation(const model::Board &board,
                                      model::Colour colour) {
        return false;
    }

    bool is_automatic_patt(const model::ChessGame game) {
        return false;
    }

} // namespace rules