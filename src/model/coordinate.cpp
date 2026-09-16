#include "model/coordinate.h"

namespace model {

    bool Coordinate::operator==(const Coordinate &rhs) const {
        return letter == rhs.get_row() && number == rhs.get_column();
    }

    Coordinate::Coordinate(char letter, const int number) {
        if (letter < constants::MIN_LETTER || letter > constants::MAX_LETTER) {
            throw std::invalid_argument(fmt::format(
                "Invalid letter value {}! Must be [a, ..., h].", letter));
        }
        if (number <= constants::MIN_INDEX || number > constants::MAX_INDEX) {
            throw std::invalid_argument(fmt::format(
                "Invalid letter value {}. Must be [1, ..., 8]. ", number));
        }
        this->letter = letter;
        this->number = number;
    }

    std::string Coordinate::to_string() const {
        return letter + std::to_string(number);
    }

    char Coordinate::get_row() const {
        return letter;
    };
    int Coordinate::get_column() const {
        return number;
    };

    int Coordinate::get_column_index() const {
        return letter - 'a';
    };

    int Coordinate::get_row_index() const {
        return constants::MAX_INDEX - number;
    }

} // namespace model