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
            auto start = parse_input_until_valid("start");
            if (!start.has_value()) {
                break; // entered x to end game
            }

            auto destination = parse_input_until_valid("destination");
            if (!destination.has_value()) {
                break; // entered x to end game
            }

            board.make_move(start.value(), destination.value());
            viewer.make_move(start.value(), destination.value());
            viewer.displayBoard(board);
        }

        viewer.end_game();
    };

  private:
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

    std::optional<model::Field>
    parse_input_until_valid(const std::string &field_type) {
        while (true) {
            try {
                return parse_input(viewer.request_field(field_type));
            } catch (std::invalid_argument &error) {
                viewer.show(error.what());
            }
        }
    }

    view::CmdView viewer;
    model::Board board;
};
