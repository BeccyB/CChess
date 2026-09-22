#pragma once

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <optional>
#include <sstream>
#include <variant>
#include "model/board.h"
#include "model/chess_game.h"
#include "model/coordinate.h"
#include "model/game_move.h"
#include "model/game_option.h"

namespace view {

    constexpr int LENGTH_COORDINATE = 2;

    void show(const std::string message);

    void show_instructions();

    void show_game_start();

    void show_game_end();

    void show_next_player(std::string name);

    void show(const model::Coordinate start,
              const model::Coordinate destination);

    void show(const model::GameMove::ValidityStatus status);

    void show(const model::Board &board, bool move_status = true);

} // namespace view