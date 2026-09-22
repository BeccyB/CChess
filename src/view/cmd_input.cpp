#include "view/cmd_input.h"
#include "view/cmd_output.h"

namespace view {
    std::string reqest_user_input(std::string message) {
        show(message);
        std::string input;
        std::cin >> input;
        return input;
    }

    std::optional<model::Coordinate> parse_coordinate(std::string input) {

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
    parse_start_and_destination(std::string input) {
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

} // namespace view