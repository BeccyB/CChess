#pragma once

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <optional>
#include <sstream>
#include <variant>
#include "model/board.h"
#include "model/coordinate.h"

namespace view {

    class CmdGui {
      public:
        void show(const std::string message) const {
            std::printf("%s\n", message.c_str());
        }

        void instructions() {
            show("Input [a-h, 1-8] or x to quit.");
        }

        std::string input_string() const {
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

        void show_move(const model::Coordinate start,
                       const model::Coordinate destination) {

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
    };

} // namespace view