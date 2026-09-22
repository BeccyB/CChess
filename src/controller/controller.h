#pragma once

#include <atomic>
#include <cstdio>
#include <exception>
#include <iostream>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <variant>

#include "fmt/core.h"
#include "model/board.h"
#include "model/chess_game.h"
#include "view/cmd_input.h"
#include "view/cmd_output.h"
#include "model/coordinate.h"
#include "model/game_move.h"
#include "model/game_option.h"

namespace controller {

    class Controller {
      public:
        void run();

        void play_chess_game();
    };

} // namespace controller
