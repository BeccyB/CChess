#include "model/board.h"
#include <algorithm>

namespace model {

    void Board::initalize_with_pawns() {
        // black is on the top
        fields.at(0).at(0) = 'c';
        fields.at(0).at(1) = 'k';
        fields.at(0).at(2) = 'b';

        fields.at(0).at(3) = 'Q';
        fields.at(0).at(4) = 'K';

        fields.at(1).fill('p');

        // copy bishop, knight, castle in reverse order
        auto begin = fields.at(0).begin();
        std::reverse_copy(begin, begin + 3, begin + 5);

        // mirror pieces upper to lower
        std::copy(fields.at(1).begin(), fields.at(1).end(),
                  fields.at(6).begin());

        std::copy(fields.at(0).begin(), fields.at(0).end(),
                  fields.at(7).begin());
    }

    void Board::set_field(const Coordinate &coordinate, const char piece) {
        fields.at(coordinate.get_row_index())
            .at(coordinate.get_column_index()) = piece;
    }

    void Board::clear_field(const Coordinate &coordinate) {
        fields.at(coordinate.get_row_index())
            .at(coordinate.get_column_index()) = empty_field;
    }

    char Board::get_field(const Coordinate &coordinate) const {
        return fields.at(coordinate.get_row_index())
            .at(coordinate.get_column_index());
    }

    bool Board::is_occupied(const Coordinate &coordinate) const {
        auto row = coordinate.get_row_index();
        auto col = coordinate.get_column_index();
        return fields.at(row).at(col) != empty_field;
    }

    const Board::Array2d &Board::get_fields() const {
        return fields;
    }

} // namespace model