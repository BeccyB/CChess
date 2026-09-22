#include "model/game_move.h"

namespace model {

    GameMove::ValidityStatus
    GameMove::determine_game_move_validity(const model::Board &board) const {

        if (!board.is_occupied(start_)) {
            return GameMove::ValidityStatus::NOT_OCCUPID;
        }

        if (board.is_occupied(destination_)) {
            return GameMove::ValidityStatus::OCCUPID;
        }

        // TODO: more checks here!!!!
        return GameMove::ValidityStatus::VALID;
    }

    bool GameMove::is_move_valid(const model::Board &board) const {
        return determine_game_move_validity(board) ==
               GameMove::ValidityStatus::VALID;
    }

    const std::pair<model::Coordinate, model::Coordinate>
    GameMove::coordinates() const {
        return {start_, destination_};
    }

    void GameMove::execute_move(Board &board) const {
        const auto piece = board.get_field(start_);
        board.clear_field(start_);
        board.set_field(destination_, piece);
    };

    bool GameMove::is_equal() const {
        return start_ == destination_;
    }
} // namespace model