#pragma once
#include <stdexcept>
#include <string>
#include <array>
#include <fmt/core.h>
#include <valarray>

namespace model {
    class Coordinate {

        char row;   // y -> letters
        int column; // x -> numbers

      public:
        bool operator==(const Coordinate &rhs) {
            return row == rhs.get_row() && column == rhs.get_column();
        }

        Coordinate(char row, std::string column) {
            if (row < 'a' || row > 'h') {
                throw std::invalid_argument(fmt::format(
                    "Invalid row value {}! Must be [a, ..., h].", row));
            }
            if (column <= "0" || column > "8") {
                throw std::invalid_argument(fmt::format(
                    "Invalid row value {}. Must be [1, ..., 8]. ", column));
            }
            this->row = row;
            this->column = std::stoi(column);
        }

        std::string to_string() const {
            return std::to_string(row) + std::to_string(column);
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