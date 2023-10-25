#pragma once

#include <string>

#include "chess/board.h"

namespace chess::ui::cmd
{

    std::string serialize(const chess::game::Board &board);
}