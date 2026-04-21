#pragma once

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <optional>
#include <sstream>
#include <variant>
#include "model/board.h"
#include "model/field.h"

namespace view {

    class CmdView {
      public:
        void show(const std::string message) const {
            std::printf("%s\n", message.c_str());
        }

        void instructions() {
            show("Input [a-h, 1-8] or x to quit.");
        }

        const std::string request_field(const std::string &field_type) const {
            show("Enter " + field_type + " field:");
            return request_input();
        }

        // TODO(bryd_re): move this somewhere else
        std::optional<model::Field> parse_input(std::string input) {

            if (input == "x" || input == "X") {
                return {};
            } else if (input.length() <= 3) {

                const auto column = input.substr(1, 1);

                return model::Field{input[0], std::stoi(column)};
            }

            throw std::invalid_argument("Invalid input!");
        }

        void start_game() {
            show("****************************************");
            show("Starting new game :) Let the game begin!");
            show("****************************************");
        }

        void end_game() {
            show("Stoping Game. Good Bye!");
        }

        void show_move(const model::Field start,
                       const model::Field destination) {

            show(fmt::format("Moving {}{} -> {}{}", start.get_row(),
                             start.get_column(), destination.get_row(),
                             destination.get_column()));
        }

        // Function to display the board
        void display_board(const model::Board &board) {
            using namespace std;
            cout << "  a  b  c  d  e  f  g  h " << endl;
            cout << " ------------------------" << endl;
            int row_index = 1;
            for (const auto rows : board.get_fields()) {
                cout << row_index;
                for (const auto col : rows) {
                    if (col) {
                        cout << " x ";
                    } else {
                        cout << "   ";
                    }
                }
                cout << row_index << endl;
                row_index++;
            }
            cout << " ------------------------" << endl;
            cout << "  a  b  c  d  e  f  g  h " << endl;
        }

      private:
        std::string request_input() const {
            std::string user_input;
            std::cin >> user_input;
            return user_input;
        }
    };

} // namespace view