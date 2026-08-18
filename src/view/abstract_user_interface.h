#pragma once

#include <utility>

#include "src/model/chessgame.h"

class Viewer {
public:
    void display_game(Chess_board& cb) const;

    std::pair<int, int> ask_user_to_select_a_pawn_that_shall_go_one_step_forward() const;

    void print_pawn_reached_other_side_and_game_over() const;
};
