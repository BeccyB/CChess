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
    struct UserInputHandler {

        model::ChessGame &game;

        void operator()(const model::GameMove move) const {
            auto status = game.handle_game_move(move);
            view::show(game.board(), status);
        }

        void operator()(const model::GameOption &option) const {
            switch (option) {
            case model::GameOption::END_GAME:
                game.set_should_stop(true);
                break;
            case model::GameOption::UNKOWN_INPUT:
                game.increment_input_request_count();
            }
        }
    };

    class Controller {
      public:
        void run();

        void play_chess_game();
    };

} // namespace controller
