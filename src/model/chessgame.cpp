#include "chessgame.h"

Position_of_pawn::Position_of_pawn(int val_x, int val_y)
    : x(val_x), y(val_y) {}

Chess_board::Chess_board()
    : _board_lower_bound_x(1), _board_upper_bound_x(8), _board_lower_bound_y(1), _board_upper_bound_y(8) {

    Position_of_pawn pawn1 (1, 2); // for loop would make code shorter and dryer
    Position_of_pawn pawn2 (2, 2);
    Position_of_pawn pawn3 (3, 2);
    Position_of_pawn pawn4 (4, 2);
    Position_of_pawn pawn5 (5, 2);
    Position_of_pawn pawn6 (6, 2);
    Position_of_pawn pawn7 (7, 2);
    Position_of_pawn pawn8 (8, 2);

    _positions = {pawn1, pawn2, pawn3, pawn4, pawn5, pawn6, pawn7, pawn8};
}

// Position_of_pawn Chess_board::get_pawn_position() const {
//     return _p;
// }

// void Chess_board::move_pawn_one_step_forward() {
//     _p.y += 1;
// }

std::vector<Position_of_pawn> Chess_board::get_positions_of_pawns() const {
    return _positions;
}

bool Chess_board::check_if_there_is_a_pawn_in_given_position(int x, int y) const {
    for (Position_of_pawn p : _positions) {
        if (p.x == x && p.y == y) {
            return true;
        }
    }
    return false;
}

bool Chess_board::pawn_reached_other_side() const {
    for(Position_of_pawn p : _positions) {
        if (p.y == 8) {
            return true;
        }
    }
    return false;
}

int Chess_board::get_board_lower_bound_x() const {
    return _board_lower_bound_x;
} 

int Chess_board::get_board_lower_bound_y() const {
    return _board_lower_bound_y;
}

int Chess_board::get_board_upper_bound_x() const {
    return _board_upper_bound_x;
}

int Chess_board::get_board_upper_bound_y() const {
    return _board_upper_bound_y;
}

bool Chess_board::selection_inside_the_field(int x, int y) const {
    return _board_lower_bound_x <= x && _board_upper_bound_x >= x &&
           _board_lower_bound_y <= x && _board_upper_bound_y >= y;
}
