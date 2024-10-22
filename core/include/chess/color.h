#pragma once

#include <string>

namespace chess
{
    /**
     * @brief Enum for color of pieces
     *
     */
    enum class Color
    {
        WHITE,
        BLACK
    };

    std::string to_string(const Color color);

}