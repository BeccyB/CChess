#pragma once
#include <atomic>
#include <cstdio>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

#include "model/board.h"
#include "view/user_interface.h"
#include "model/field.h"

namespace chessgame {

    class ChessGame {

      public:
        ChessGame(view::CmdView &viewer_) : viewer(viewer_){};

        void loop() {

            viewer.start_game();
            viewer.instructions();

            auto init = user_request_field_input("initial");
            if (init.has_value()) {
                board.set_field(init.value(), true);
                viewer.display_board(board);

                while (true) {
                    auto start = user_request_field_input("start");
                    if (!start.has_value()) {
                        break; // entered x to end game
                    }

                    // CHECK if field has pawn
                    if (!board.is_occupied(start.value())) {
                        viewer.show("Please choose field with pawn!");
                        break;
                    };

                    auto destination = user_request_field_input("destination");
                    if (!destination.has_value()) {
                        break; // entered x to end game
                    }

                    board.make_move(start.value(), destination.value());

                    viewer.show_move(start.value(), destination.value());
                    viewer.display_board(board);
                }
            }

            viewer.end_game();
        };

      private:
        std::optional<model::Field>
        user_request_field_input(const std::string &field_type,
                                 const int max_requests = 10) {
            int requests = 0;
            while (true && requests < max_requests) {
                try {
                    return viewer.parse_input(viewer.request_field(field_type));
                } catch (std::invalid_argument &error) {
                    viewer.show(error.what());
                }
                ++requests;
            }
            return {};
        }

        view::CmdView &viewer;
        model::Board board;
    };

} // namespace chessgame