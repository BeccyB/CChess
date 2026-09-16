#include "model/game_move.h"

namespace model {
    const std::pair<model::Coordinate, model::Coordinate>
    GameMove::coordinates() const {
        return {start_, destination_};
    }

    bool GameMove::is_equal() const {
        return start_ == destination_;
    }
} // namespace model