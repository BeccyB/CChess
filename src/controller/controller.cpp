#include "controller/controller.h"
#include "view/cmd_input.h"
#include "view/cmd_output.h"

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

                // combine these two lines
                const auto raw_input = view::reqest_user_input();
                const auto input = view::parse_user_input(raw_input);

                std::visit(UserInputHandler{game}, input);

            } catch (std::exception) {
                view::show("Error occured while making chess move!");
            }
        }

        view::show_game_end();
    }
} // namespace controller