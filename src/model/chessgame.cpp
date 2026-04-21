#include "chessgame.h"

Chess_board::Chess_board() {
    Position_of_pawn p;
    p.x = 3;
    p.y = 1;
    _p = p;
}

Position_of_pawn Chess_board::get_pawn_position() {
    return _p;
}

void Chess_board::move_pawn_one_step_forward() {
    _p.y =+ 1;
}