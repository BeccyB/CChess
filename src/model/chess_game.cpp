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
        return colours[current_player()];
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

        std::cout << next_move.is_equal() << std::endl;
        auto [start, dest] = next_move.coordinates();

        if (board_.is_move_valid(next_move)) {

            board_.make_move(next_move);
            history_.push_back(next_move);
            return true;
        }
        return false;
    }

} // namespace model