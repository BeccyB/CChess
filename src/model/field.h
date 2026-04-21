#pragma once
#include <stdexcept>
#include <string>
#include <array>
#include <fmt/core.h>

namespace model {
    class Field {

        char row;   // y -> letters
        int column; // x -> numbers

      public:
        Field(char row, int column) {
            if (row < 'a' || row > 'h') {
                throw std::invalid_argument(fmt::format(
                    "Invalid row value {}! Must be [a, ..., h].", row));
            }
            if (column < 0 || column > 8) {
                throw std::invalid_argument(fmt::format(
                    "Invalid row value {}. Must be [1, ..., 8]. ", column));
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
            return row - 'a';
        };

        int get_row_index() const {
            return column - 1;
        }
    };

} // namespace model