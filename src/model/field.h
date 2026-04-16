#pragma once
#include <stdexcept>
#include <string>
#include <array>
#include <fmt/core.h>

namespace model {
    class Field {

        char row;   // y -> numbers
        int column; // x -> letters

      public:
        Field(char row, int column) {
            if (row < 'A' || row > 'H') {
                throw std::invalid_argument(fmt::format(
                    "Invalid row value {}! Must be [A, ..., H].", row));
            }
            if (column < 0 || column > 8) {
                throw std::invalid_argument(fmt::format(
                    "Invalid row value {}. Must be [A, ..., H]. ", column));
            }
            this->row = row;
            this->column = column;
        }

        char get_row() const {
            return row;
        };
        int get_column() const {
            return column;
        };

        int get_column_index() const {
            // TODO(bryd_re): map row letters to integer
            return row - 'A';
        };

        int get_row_index() const {
            return column - 1; // start from 0 in board
        }
    };

} // namespace model