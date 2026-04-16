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

class Controller {
  public:
    void loop() {
        viewer.start_game();
        viewer.instructions();

        viewer.displayBoard(board);

        while (true) {

            std::optional<model::Field> start;
            std::optional<model::Field> destination;

            try {
                start = parse_input(viewer.request_start_field());
                if (!start.has_value()) {
                    break;
                }

            } catch (std::invalid_argument &error) {
                viewer.invalid_input();
            }

            try {
                destination = parse_input(viewer.request_destination_field());
                if (!destination.has_value()) {
                    break;
                }
            } catch (std::invalid_argument &error) {
                viewer.invalid_input();
            }

            viewer.make_move(start.value(), destination.value());
            board.make_move(start.value(), destination.value());

            viewer.show_board(board);
        }
    };

  private:
    // TODO(bryd_re): move this somewhere else
    std::optional<model::Field> parse_input(std::string input) {

        // how to map the three cases: quit, row/col, invalid input
        if (input == "x" || input == "X") {
            return {};
        } else if (input.length() <= 3) {

            const auto column = input.substr(1, 1);

            return model::Field{input[0], std::stoi(column)};
        }

        throw std::invalid_argument("Invalid input.");
    }

    view::CmdView viewer;
    model::Board board;
};
