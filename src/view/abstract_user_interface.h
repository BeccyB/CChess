#pragma once

#include "src/model/chessgame.h"

class Viewer {
public:
    void display_game(Position_of_pawn p);

    bool ask_user_if_pawn_should_go_one_step_forward();
};
