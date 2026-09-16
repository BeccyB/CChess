#pragma once
#include <stdexcept>
#include <string>
#include <array>
#include <fmt/core.h>
#include <valarray>

namespace model {

    namespace constants {
        constexpr int MIN_INDEX = 0;
        constexpr int MAX_INDEX = 8;
        constexpr char MIN_LETTER = 'a';
        constexpr char MAX_LETTER = 'h';
    } // namespace constants

    class Coordinate {

        char letter; // y -> letters
        int number;  // x -> numbers

      public:
        bool operator==(const Coordinate &rhs) const;

        Coordinate(char letter, const int number);

        std::string to_string() const;

        char get_row() const;
        int get_column() const;

        int get_column_index() const;

        int get_row_index() const;
    };

} // namespace model