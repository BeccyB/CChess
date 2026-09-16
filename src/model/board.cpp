#include "model/board.h"

namespace model {

    void Board::initalize_with_pawns() {
        for (int i = constants::MIN_INDEX; i < constants::MAX_INDEX; ++i) {
            fields.at(1).at(i) = 'P';
            fields.at(6).at(i) = 'P';
        }
        fields.at(0).at(3) = 'Q'; // black is on the top
        fields.at(7).at(3) = 'Q'; // white is on the botton
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

    GameMoveValidityStatus Board::determine_game_move_validity(
        const model::GameMove &next_move) const {
        const auto [start, destination] = next_move.coordinates();

        if (!is_occupied(start)) {
            return GameMoveValidityStatus::NOT_OCCUPID;
        }

        if (is_occupied(destination)) {
            return GameMoveValidityStatus::OCCUPID;
        }

        // TODO: more checks here!!!!
        return GameMoveValidityStatus::VALID;
    }

    bool Board::is_move_valid(const model::GameMove move) const {
        return determine_game_move_validity(move) ==
               GameMoveValidityStatus::VALID;
    }
} // namespace model