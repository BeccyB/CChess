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

        auto begin = fields.at(0).begin();
        std::copy_backward(begin, begin + 3, fields.at(0).end());
        std::reverse_copy(begin, begin + 3, begin + 5);

        std::copy(fields.at(1).begin(), fields.at(1).end(),
                  fields.at(6).begin());

        std::copy(fields.at(0).begin(), fields.at(0).end(),
                  fields.at(7).begin());
    }

    void Board::make_move(const GameMove next_move) {
        const auto [start, destination] = next_move.coordinates();

        const auto piece = get_field(start);
        set_field(start, empty_field);
        set_field(destination, piece);
    };

    void Board::set_field(const Coordinate &coordinate, const char piece) {
        fields.at(coordinate.get_row_index())
            .at(coordinate.get_column_index()) = piece;
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

    GameMove::ValidityStatus Board::determine_game_move_validity(
        const model::GameMove &next_move) const {
        const auto [start, destination] = next_move.coordinates();

        if (!is_occupied(start)) {
            return GameMove::ValidityStatus::NOT_OCCUPID;
        }

        if (is_occupied(destination)) {
            return GameMove::ValidityStatus::OCCUPID;
        }

        // TODO: more checks here!!!!
        return GameMove::ValidityStatus::VALID;
    }

    bool Board::is_move_valid(const model::GameMove move) const {
        return determine_game_move_validity(move) ==
               GameMove::ValidityStatus::VALID;
    }
} // namespace model