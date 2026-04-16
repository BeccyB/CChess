#pragma once
#include <string>
#include <array>

namespace model {
    struct Field {

        char row;   // y -> numbers
        int column; // x -> letters

        int get_column_index() const {
            // TODO(bryd_re): map row letters to integer
            return row - 'A';
        };

        int get_row_index() const {
            return column - 1; // start from 0 in board
        }
    };

} // namespace model