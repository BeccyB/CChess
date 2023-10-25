#include "chess/board.h"
#include "chess/common.h"

#include <stdexcept>
#include <iostream>

namespace chess::game
{
    Board::Board()
    {
        std::for_each(board_.begin(), board_.end(), [](auto &field)
                      { field = {}; });
    }

    Board::Board(std::initializer_list<std::tuple<int, int, Piece>> initial_pieces)
    {

        std::for_each(initial_pieces.begin(), initial_pieces.end(), [this](auto &entry)
                      {
            
            auto& [x, y, piece] = entry;
            std::cout << x << " " << y << " " << std::endl;

            board_[x + y * max_index_] = std::make_optional<Piece>(std::move(piece)); });
    }

    bool Board::is_within_board(const int x, const int y) const
    {
        return x >= min_index_ && x < max_index_ && y >= min_index_ && y < max_index_;
    }

    std::optional<Piece> &Board::at(const int x, const int y)
    {
        if (!is_within_board(x, y))
        {
            throw std::out_of_range("x or y out of range: must be between 1 and 8");
        }
        return board_[x + y * max_index_];
    }

    const std::optional<Piece> &Board::at(const int x, const int y) const
    {
        if (!is_within_board(x, y))
        {
            throw std::out_of_range("x or y out of range: must be between 1 and 8");
        }
        return board_[x + y * max_index_];
    }

    bool Board::is_free_field(int x, int y) const
    {
        return !at(x, y).has_value();
    }

    bool Board::is_occupied_field(int x, int y) const
    {
        return at(x, y).has_value();
    }

    bool Board::move(const int source_x, const int source_y, const int destination_x, const int destination_y)
    {

        if (is_free_field(source_x, source_y))
        {
            std::cout << "Source field is free!" << std::endl;
            return false;
        }
        if (is_occupied_field(destination_x, destination_y))
        {
            std::cout << "Destination field is occupied!" << std::endl;
            return false;
        }
        auto piece = at(source_x, source_y);
        at(destination_x, destination_y) = piece;
        at(source_x, source_y) = {};
        return true;
    }

}