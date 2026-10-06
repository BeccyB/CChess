#include "chess_game.h"
#include "model/chess_piece.h"
#include "model/game_move.h"

#include <iostream>

namespace model {

    ChessGame::ChessGame() {
        board_.initalize_with_pawns();
    }

    const Board &ChessGame::board() const {
        return board_;
    }

    void ChessGame::switch_to_next_colour() {
        current_colour_ =
            current_colour_ == Colour::WHITE ? Colour::BLACK : Colour::WHITE;
    }

    Colour ChessGame::current_colour() const {
        return current_colour_;
    }

    Colour ChessGame::opponent_colour() const {
        return current_colour_ == Colour::WHITE ? Colour::BLACK : Colour::WHITE;
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

    void ChessGame::execute_move(const model::GameMove next_move) {

        auto [start, destination] = next_move.coordinates();
        const auto piece = board_.get_field(start);
        board_.clear_field(start);
        board_.set_field(destination, piece);
    };

    void ChessGame::save_to_history(const model::GameMove move) {
        history_.push_back(move);
    }

} // namespace model