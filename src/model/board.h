#pragma once
#include "model/field.h"
#include <array>
#include <iostream>

namespace model {
    class Board {

      public:
        using Array2d = std::array<std::array<bool, 8>, 8>;

        Board() {
            // empty board initalization
            for (auto &row : fields) {
                row.fill(false);
            }
        }

        void make_move(const Field &start, const Field &destination) {
            set_field(start, false);
            set_field(destination, true);
        };

        void set_field(const Field &field, const bool state) {
            fields.at(field.get_row_index()).at(field.get_column_index()) =
                state;
        }

        bool is_occupied(const Field &field) const {
            return fields.at(field.get_row_index())
                .at(field.get_column_index());
        }

        const Array2d &get_fields() const {
            return fields;
        }

      private:
        Array2d fields;
    };
} // namespace model