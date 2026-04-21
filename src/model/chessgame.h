#pragma once

struct Position_of_pawn {
    int x;
    int y;
};

class Chess_board {
public:
    Chess_board();

    Position_of_pawn get_pawn_position();

    void move_pawn_one_step_forward();

private:
    Position_of_pawn _p;
};