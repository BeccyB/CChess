#include "chess_game.h"

#include <iostream>

namespace model {

    ChessGame::ChessGame() {
        board_.initalize_with_pawns();
    }

    const Board &ChessGame::board() const {
        return board_;
    }

    void ChessGame::switch_to_next_player() {
        ++current_player_index_ %= 2;
    }

    int ChessGame::current_player() const {
        return current_player_index_;
    }

    std::string ChessGame::current_colour() const {
        return colours_[current_player()];
    }

    void ChessGame::increment_input_request_count() {
        ++input_request_count_;
    }

    void ChessGame::set_should_stop(bool value) {
        should_stop_ = value;
    }

    bool ChessGame::should_stop() const {
        return should_stop_ || input_request_count_ > MAX_INPUT_REQUESTS;
    }

    bool ChessGame::handle_game_move(const model::GameMove next_move) {

        if (next_move.is_move_valid(board_)) {

            next_move.execute_move(board_);
            history_.push_back(next_move);
            switch_to_next_player();

            return true;
        }
        return false;
    }

} // namespace model