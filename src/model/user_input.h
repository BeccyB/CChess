#pragma once

#include <variant>
#include "model/game_move.h"
#include "model/game_option.h"

namespace model {

    using UserInput = std::variant<model::GameMove, model::GameOption>;

}