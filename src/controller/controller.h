#pragma once

#include "src/view/abstract_user_interface.h"
#include "src/model/chessgame.h"


class Controller {
public:
    Controller(); 

    void run_game();

private:
    Viewer _viewer;
    Chess_board _board;
};





