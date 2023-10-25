#pragma once

#include <string>

#include "common.h"

namespace chess::game
{

    /**
     * @brief Player object containing name and color
     *
     */
    struct Player
    {
        std::string name;
        Color color;
    };
}
