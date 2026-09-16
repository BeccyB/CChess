#pragma once

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <optional>
#include <sstream>
#include <variant>
#include "model/board.h"
#include "model/coordinate.h"
#include "model/game_move.h"
#include "model/game_option.h"
#include "model/game_move_validity_status.h"

namespace view {

    constexpr int LENGTH_COORDINATE = 2;

    class CmdBoard {

      private:
        std::string letter_header = "  |  a  b  c  d  e  f  g  h |  ";
        std::string horizontal_separator = "--|-------------------------|--";
        std::string empty_field_display = "   ";

      public:
        CmdBoard() = default;

        void display(const model::Board &board) {

            using namespace std;

            auto row_index = model::constants::MAX_INDEX;
            cout << letter_header << endl;
            cout << horizontal_separator << endl;

            for (const auto rows : board.get_fields()) {

                // display numbers on the left
                cout << row_index << " | ";

                for (const auto col : rows) {
                    if (col == 'e') {
                        cout << empty_field_display;
                    } else {
                        cout << " " << col << " ";
                    }
                }

                // display numbers on the right
                cout << "| " << row_index << endl;
                row_index--;
            }

            cout << horizontal_separator << endl;
            cout << letter_header << endl;
        }
    };

    class CmdGui {

      private:
        CmdBoard gui_board_;

      public:
        CmdGui() = default;

        void show(const std::string message) const {
            std::printf("%s\n", message.c_str());
        }

        void instructions() {
            show("Input <a-h><1-8> or x to quit.");
        }

        std::string reqest_user_input(std::string message = "") const {
            show(message);
            std::string input;
            std::cin >> input;
            return input;
        }

        void start_game() {
            show("****************************************");
            show("Starting new game :) Let the game begin!");
            show("****************************************");
        }

        void end_game() {
            show("Stoping Game. Good Bye!");
        }

        void show_next_player(std::string name) {
            // make this a member variable of gui!
            show(fmt::format("{}, it is your turn:", name));
        }

        void show_move(const model::Coordinate start,
                       const model::Coordinate destination) {

            show(fmt::format("Moving {}{} -> {}{}", start.get_row(),
                             start.get_column(), destination.get_row(),
                             destination.get_column()));
        }

        // Function to display the board
        void display_board(const model::Board &board) {
            gui_board_.display(board);
        }

        void validity_message(const model::GameMoveValidityStatus status) {

            switch (status) {
            case model::GameMoveValidityStatus::NOT_OCCUPID:
                show("You selected an empty field.");
                break;
            case model::GameMoveValidityStatus::OCCUPID:
                show("You selected an occupied field.");
                break;
            case model::GameMoveValidityStatus::VALID:
                show("Valid input.");
                break;
            }
        }

        std::optional<model::Coordinate>
        parse_coordinate(std::string input) const {

            try {
                const auto row = input[0];
                const auto column = std::stoi(input.substr(1, 1));

                const auto coordinate = model::Coordinate(row, column);

                return coordinate;

            } catch (const std::out_of_range &error) {
                show(error.what());
                // TODO log the input the user gave and show somehow to user!
            }
            return {};
        }

        std::optional<model::GameMove>
        parse_start_and_destination(std::string input) const {
            try {
                const auto start =
                    parse_coordinate(input.substr(0, LENGTH_COORDINATE));
                const auto destination = parse_coordinate(
                    input.substr(LENGTH_COORDINATE, LENGTH_COORDINATE));

                if (start.has_value() && destination.has_value()) {
                    return model::GameMove(start.value(), destination.value());
                }

            } catch (const std::out_of_range &error) {
                show(error.what());
                // TODO log the input the user gave and show somehow to user!
            }

            show("Failed to parse start/destination");
            return {};
        }

        std::variant<model::GameMove, model::GameOption>
        parse_user_input(std::string input) {

            if (input == "x" || input == "X" || input == "q") {
                return model::GameOption::END_GAME;

            } else if (input.length() == 2 * LENGTH_COORDINATE) {
                auto result = parse_start_and_destination(input);

                if (result.has_value()) {
                    return result.value();
                }
            }

            return model::GameOption::UNKOWN_INPUT;
        }
    };

} // namespace view