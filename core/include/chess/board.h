#pragma once

#include <array>
#include <string>
#include <tuple>
#include <optional>

#include "chess/piece.h"

namespace chess::game
{
    class Board
    {

    public:
        Board();

        Board(std::initializer_list<std::tuple<int, int, Piece>> initial_pieces);

        using board_iterator = std::array<std::optional<chess::game::Piece>, 64>::iterator;
        using const_board_iterator = std::array<std::optional<chess::game::Piece>, 64>::const_iterator;

        board_iterator begin() { return board_.begin(); }
        board_iterator end() { return board_.end(); }
        const_board_iterator cbegin() const { return board_.cbegin(); }
        const_board_iterator cend() const { return board_.cend(); }

        const int width() const { return max_index_; }
        const int number_of_fields() const { return board_.size(); }

        std::optional<Piece> &at(const int x, const int y);
        const std::optional<Piece> &at(const int x, const int y) const;

        bool is_within_board(const int x, const int y) const;
        bool is_free_field(const int x, const int y) const;
        bool is_occupied_field(const int x, const int y) const;

        bool move(const int source_x, const int source_y, const int destination_x, const int destination_y);

    private:
        std::array<std::optional<Piece>, 64> board_;
        const int min_index_ = 0;
        const int max_index_ = 8;
    };
} // namespace game
