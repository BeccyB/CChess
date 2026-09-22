#pragma once
#include "model/chess_game.h"
#include "view/cmd_input.h"

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
} // namespace controller