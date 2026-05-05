#include "chessgame.h"

Position_of_pawn::Position_of_pawn(int val_x, int val_y)
    : x(val_x), y(val_y) {}

Chess_board::Chess_board()
    : _p(3, 1) {}

Position_of_pawn Chess_board::get_pawn_position() {
    return _p;
}

void Chess_board::move_pawn_one_step_forward() {
    _p.y += 1;
}