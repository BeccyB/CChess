#include "controller/controller.h"
#include "view/cmd_input.h"
#include "view/cmd_output.h"

#include "controller/user_input_handler.h"

namespace controller {

    void Controller::run() {
        play_chess_game();
    }

    void Controller::play_chess_game() {
        using namespace ::model;

        ChessGame game;

        view::show_game_start();
        view::show(game.board());

        const std::array<std::string, 2> colours = {"white", "black"};

        while (!game.should_stop()) {
            try {
                view::show_next_player(game.current_colour());

                std::visit(UserInputHandler{game}, view::user_input());

            } catch (std::exception) {
                view::show("Error occured while making chess move!");
            }
        }

        view::show_game_end();
    }
} // namespace controller