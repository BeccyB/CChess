#pragma once
#include "model/field.h"
#include <array>
#include <iostream>

namespace model {
    struct Board {
        // array of rows
        std::array<std::array<bool, 8>, 8> fields;

        Board() {
            // Set all values to false
            for (auto &row : fields) {
                row.fill(false);
            }
        }

        void make_move(const model::Field start,
                       const model::Field destination) {

            fields.at(start.get_row_index()).at(start.get_column_index()) =
                false;
            fields.at(destination.get_row_index())
                .at(destination.get_column_index()) = true;
        };

        std::array<char, 8> row_letter = {'A', 'B', 'C', 'D',
                                          'E', 'F', 'G', 'H'};
    };
} // namespace model