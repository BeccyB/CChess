#pragma once

#include "model/chess_piece.h"
#include "model/game_move.h"
#include "model/board.h"
#include "view/cmd_input.h"
#include "view/cmd_output.h"
#include "model/coordinate.h"
#include "model/game_move.h"
#include "model/game_option.h"
#include <vector>
#include <iostream>

namespace model {
    constexpr auto MAX_INPUT_REQUESTS = 30;

    class ChessGame {

      private:
        Colour current_colour_ = Colour::WHITE;
        int input_request_count_ = 0;

        bool should_stop_ = false;
        std::vector<GameMove> history_ = {};
        Board board_;

      public:
        ChessGame();
        ~ChessGame() = default;

        const Board &board() const;

        void switch_to_next_colour();

        Colour current_colour() const;

        Colour opponent_colour() const;

        void increment_input_request_count();

        void set_should_stop(bool value);

        bool should_stop() const;

        void execute_move(const model::GameMove next_move);

        void save_to_history(const model::GameMove move);
    };
} // namespace model