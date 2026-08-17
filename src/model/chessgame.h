#pragma once

#include <vector>

struct Position_of_pawn {
    Position_of_pawn(int val_x, int val_y);
    
    int x, y;
};

class Chess_board {
public:
    Chess_board();

    // Position_of_pawn get_pawn_position() const;

    // void move_pawn_one_step_forward();

    bool check_if_there_is_a_pawn_in_given_position(int x, int y) const;

    bool pawn_reached_other_side() const;

    std::vector<Position_of_pawn> get_positions_of_pawns() const;

    int get_board_lower_bound_x() const;
    int get_board_lower_bound_y() const;
    int get_board_upper_bound_x() const;
    int get_board_upper_bound_y() const;

    bool selection_inside_the_field(int x, int y) const;
    
    void move_pawn_one_step_forward(int x, int y);

private:
    std::vector<Position_of_pawn> _positions;
    int _board_lower_bound_x; // counting starts with 1, as in real chess
    int _board_lower_bound_y;
    int _board_upper_bound_x;
    int _board_upper_bound_y;

};