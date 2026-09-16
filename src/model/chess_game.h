#pragma once

#include "model/game_move.h"
#include "model/board.h"
#include "view/user_interface.h"
#include "model/coordinate.h"
#include "model/game_move.h"
#include "model/game_option.h"
#include <vector>
#include <iostream>

namespace model {
    constexpr auto MAX_INPUT_REQUESTS = 30;

    class ChessGame {

      private:
        int current_player_index_ = 0;
        int input_request_count_ = 0;
        bool should_stop_ = false;
        std::array<std::string, 2> colours = {"white", "black"};
        std::vector<GameMove> history_ = {};
        Board board_;

      public:
        ChessGame();
        ~ChessGame() = default;

        const Board &board() const;

        void switch_to_next_player();

        int current_player() const;

        std::string current_colour() const;

        void increment_input_request_count();

        void set_should_stop(bool value);

        bool should_stop() const;

        bool handle_game_move(const model::GameMove next_move);
    };
} // namespace model