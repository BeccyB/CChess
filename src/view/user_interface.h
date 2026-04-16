#pragma once

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "model/board.h"
#include "model/field.h"

namespace view {

    class CmdView {
      public:
        void show(const std::string message) const {
            std::printf("%s\n", message.c_str());
        }

        void instructions() {
            show("Input format: <letter><number> e.g. F6");
            show("Type x to stop.");
        }

        const std::string request_start_field() const {
            show("Enter start field:");
            return request_input();
        }

        const std::string request_destination_field() const {
            show("Enter destination field:");
            return request_input();
        }

        void start_game() {
            show("****************************************");
            show("Starting new game :) Let the game begin!");
            show("****************************************");
        }

        void end_game() {
            show("Stoping Game. Good Bye!");
        }

        void invalid_input() {
            show("Invalid!");
            instructions();
        }

        void make_move(const model::Field start,
                       const model::Field destination) {

            std::stringstream ss;

            ss << "Moving " << start.row << start.column << " -> "
               << destination.row << destination.column;

            show(ss.str());
        }

        void show_board(const model::Board &board) {

            std::for_each(board.fields.cbegin(), board.fields.cend(),
                          [](const auto &row) {
                              // TODO
                          });
        }

        // Function to display the board
        void displayBoard(const model::Board &board) {
            using namespace std;
            cout << "   a  b  c  d  e  f  g  h" << endl;
            cout << "  ------------------------" << endl;
            // indexing (row, col)
            for (const auto rows : board.fields) {
                for (const auto col : rows) {
                    if (col) {
                        // chess pice
                        cout << " x ";
                    } else {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
            cout << "  ------------------------" << endl;
            cout << "   a  b  c  d  e  f  g  h" << endl;
        }

      private:
        std::string request_input() const {
            std::string user_input;
            std::cin >> user_input;
            return user_input;
        }
    };

} // namespace view