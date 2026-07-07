#pragma once
#include "model/coordinate.h"
#include <array>
#include <iostream>

namespace model {

    class Board {

        int min = 0;
        int max = 8;

      public:
        using Array2d = std::array<std::array<bool, 8>, 8>;

        Board() {
            // empty board initalization
            for (auto &row : fields) {
                row.fill(false);
            }
        }

        void initalize_with_pawns() {
            for (int i = min; i < max; ++i) {
                fields.at(1).at(i) = true;
                fields.at(6).at(i) = true;
            }
        }

        void make_move(const Coordinate &start, const Coordinate &destination) {
            set_field(start, false);
            set_field(destination, true);
        };

        void set_field(const Coordinate &coordinate, const bool state) {
            fields.at(coordinate.get_row_index())
                .at(coordinate.get_column_index()) = state;
        }

        bool is_occupied(const Coordinate &coordinate) const {
            return fields.at(coordinate.get_row_index())
                .at(coordinate.get_column_index());
        }

        const Array2d &get_fields() const {
            return fields;
        }

      private:
        Array2d fields;
    };
} // namespace model