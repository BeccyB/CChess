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
#include "view/user_interface.h"
#include "model/coordinate.h"
#include "model/game_move.h"
#include "model/game_option.h"

namespace controller {
    struct UserInputHandler {

        model::ChessGame &game;
        view::CmdGui &gui;

        void operator()(const model::GameMove move) const {
            const auto status = game.handle_game_move(move);

            if (status) {
                game.switch_to_next_player();
                gui.display_board(game.board());
            } else {
                gui.show("Invalid move!");
            }
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

      private:
        view::CmdGui gui;
    };

} // namespace controller
