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

namespace view {

    std::string reqest_user_input(std::string message = "");

    std::optional<model::Coordinate> parse_coordinate(std::string input);

    std::optional<model::GameMove>
    parse_start_and_destination(std::string input);

    std::variant<model::GameMove, model::GameOption>
    parse_user_input(std::string input);

} // namespace view