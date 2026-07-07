#pragma once

#include <atomic>
#include <cstdio>
#include <exception>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <variant>

#include "model/board.h"
#include "view/user_interface.h"
#include "model/coordinate.h"
#include "model/game_move.h"

class Controller {

    enum GameOption {
        END_GAME, // end game, no storage
        UNKOWN_INPUT,
        // END_GAME_WITH_STORE, // end current
        // NEW_GAME_WITH_STORE, // store current and start new
    };

  public:
    void run() {

        // another loop
        // while (true) {

        // gui menu
        // user select new game

        play_chess_game();
        // user input to end program
        //}
    }

    std::variant<model::Coordinate, GameOption> parse_input(std::string input) {

        gui.show("Give input:");
        if (input == "x" || input == "X") {
            return GameOption::END_GAME;
        } else if (input.length() == 2) {
            try {
                const auto column = input.substr(1, 1);
                return model::Coordinate{input[0], column};
            } catch (const std::out_of_range &error) {
                gui.show(error.what());
                // TODO log the input the user gave and show somehow to user!
            }
        }

        return GameOption::UNKOWN_INPUT;
    }

    std::variant<model::Coordinate, GameOption>
    request_input(const int max_requests = 10) {
        int requests = 0;
        while (requests < max_requests) {

            const auto input = parse_input(gui.input_string());

            ++requests;
        }
        return END_GAME;
    }

    void validity_message(const model::GameMove::ValidityStatus status) {

        switch (status) {
        case model::GameMove::ValidityStatus::NOT_OCCUPID:
            gui.show("You selected an empty field.");
            break;
        case model::GameMove::ValidityStatus::OCCUPID:
            gui.show("You selected an occupied field.");
            break;
        case model::GameMove::ValidityStatus::VALID:
            gui.show("Valid input.");
            break;
        }
    }

    void play_chess_game() {

        model::Board board;
        board.initalize_with_pawns();

        gui.start_game();
        gui.instructions();
        gui.display_board(board);

        model::GameMove next_move;

        const auto max_input_requests = 3;
        auto input_request_count = 0;
        bool should_stop = false;

        while (!should_stop && input_request_count < max_input_requests) {

            const auto input = parse_input(gui.input_string());

            if (std::holds_alternative<model::Coordinate>(input)) {
                auto status = next_move.set_if_valid(
                    board, std::get<model::Coordinate>(input));
                if (status != model::GameMove::ValidityStatus::VALID) {
                    validity_message(status);
                    ++input_request_count;
                    continue;
                }

                if (next_move.ready()) {

                    auto [start, destination] = next_move.get();

                    board.make_move(start, destination);
                    gui.show_move(start, destination);
                    gui.display_board(board);

                    input_request_count = 0;
                    next_move.reset();

                    continue;
                }
            }

            if (std::holds_alternative<GameOption>(input)) {
                switch (std::get<GameOption>(input)) {
                case END_GAME:
                    should_stop = true;
                    break;
                case UNKOWN_INPUT:
                    ++input_request_count;
                }
            }
        }

        gui.end_game();
    }

  private:
    view::CmdGui gui;
};
