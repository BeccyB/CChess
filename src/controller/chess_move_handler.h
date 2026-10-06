#pragma once
#include "model/chess_game.h"
#include "model/game_option.h"
#include "view/cmd_input.h"
#include "controller/chess_rules.h"
#include "view/cmd_output.h"

namespace controller {
    struct ChessMoveHandler {

        model::ChessGame &game;
        bool is_check;

        void operator()(const model::GameMove next_move) const {

            auto status =
                rules::determine_game_move_validity(game.board(), next_move);

            if (status != model::ChessMoveStatus::VALID) {
                // TODO(rebecca): give feed back why invalid?
                view::show("Invalid move!");
                return;
            }

            // update all related models
            game.execute_move(next_move);
            game.switch_to_next_colour();
            game.save_to_history(next_move);

            view::show(game.board());
        }

        void operator()(const model::GameOption &option) const {
            switch (option) {
            case model::GameOption::END_GAME:
                game.set_should_stop(true);
                break;
            case model::GameOption::SHOW_INSTRUCTIONS:
                view::show_instructions();
            case model::GameOption::UNKOWN_INPUT:
                game.increment_input_request_count();
            }
        }
    };
} // namespace controller