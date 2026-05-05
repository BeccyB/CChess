#include "controller.h"

#include <iostream>

Controller::Controller() 
    : _viewer(), _board() {}

void Controller::run_game() {

    int max_steps = 8;
    int count_steps = 0;

    while (count_steps < max_steps) {
        _viewer.display_game(_board.get_pawn_position());
        
        if (_viewer.ask_user_if_pawn_should_go_one_step_forward()) {
            _board.move_pawn_one_step_forward();
            count_steps ++;
        }

    }

    std::cout << "Pawn reached other side.  GAME OVER." << std::endl;
}
