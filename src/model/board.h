#pragma once
#include "coordinate.h"
#include "model/game_move.h"
#include "model/coordinate.h"

#include <array>
#include <iostream>
#include <optional>

namespace model {

    class Board {

      public:
        char empty_field = 'e';

        using Array2d = std::array<std::array<char, constants::MAX_INDEX>,
                                   constants::MAX_INDEX>;

        Board() {
            // empty board initalization
            for (auto &row : fields) {
                row.fill(empty_field);
            }
        }

        void initalize_with_pawns();

        void make_move(const GameMove next_move);

        void set_field(const Coordinate &coordinate, const char piece);

        char get_field(const Coordinate &coordinate) const;

        bool is_occupied(const Coordinate &coordinate) const;

        const Array2d &get_fields() const;

        GameMove::ValidityStatus
        determine_game_move_validity(const model::GameMove &next_move) const;

        bool is_move_valid(const model::GameMove move) const;

      private:
        Array2d fields;
    };
} // namespace model