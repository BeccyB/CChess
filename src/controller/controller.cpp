#include "controller/controller.h"
#include "controller/chess_rules.h"
#include "view/cmd_input.h"
#include "view/cmd_output.h"

#include "controller/chess_move_handler.h"

namespace controller {

    void Controller::run() {
        play_chess_game();
    }

    void Controller::play_chess_game() {
        using namespace ::model;

        ChessGame game;

        view::show_game_start();
        view::show(game.board());

        while (!game.should_stop()) {
            try {

                bool is_check = rules::is_colour_in_check_situation(
                    game.board(), game.current_colour());

                if (is_check && rules::is_colour_check_mate(
                                    game.board(), game.current_colour())) {

                    view::show_game_wone(game.opponent_colour());
                    break;
                }

                view::show_next_player(game.current_colour());

                // handle user input
                // A) Make move
                // B) End Game / Show menu
                std::visit(ChessMoveHandler{game, is_check},
                           view::user_input());

                if (rules::is_automatic_patt(game)) {
                    view::show("Your have rached a patt situation!");
                    break;
                }

            } catch (std::exception) {
                view::show("Error occured while making chess move!");
            }
        }

        view::show_game_end();
    }
} // namespace controller