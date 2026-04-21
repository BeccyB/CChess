#include "controller.h"

Controller::Controller() {
    Viewer v;
    _viewer = v;

    Chess_board b;
    _board = b;
}

void Controller::run_game() {

    int max_steps = 8;
    int steps = 0;
    while (steps < max_steps) {
        // _viewer.display_game();

        steps ++;
    }
}
