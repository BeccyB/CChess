#pragma once

#include <atomic>
#include <cstdio>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

#include "model/board.h"
#include "view/user_interface.h"
#include "model/field.h"
#include "model/chessgame.h"

class Controller {
  public:
    void start() {

        chessgame::ChessGame game(viewer);
        game.loop();
    }

  private:
    view::CmdView viewer;
};
