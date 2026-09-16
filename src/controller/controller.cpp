#include "controller/controller.h"

namespace controller {

    void Controller::run() {
        play_chess_game();
    }

    void Controller::play_chess_game() {
        using namespace ::model;

        ChessGame game;

        gui.start_game();
        gui.instructions();
        gui.display_board(game.board());

        const std::array<std::string, 2> colours = {"white", "black"};

        while (!game.should_stop()) {
            try {
                gui.show_next_player(game.current_colour());

                // combine these two lines
                const auto raw_input = gui.reqest_user_input();
                const auto input = gui.parse_user_input(raw_input);

                std::visit(UserInputHandler{game, gui}, input);

            } catch (std::exception) {
                gui.show("Error occured while making chess move!");
            }
        }

        gui.end_game();
    }
} // namespace controller