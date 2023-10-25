#include <iostream>
#include <vector>
#include <array>

#include "chess/player.h"
#include "chess/board.h"
#include "chess/common.h"
#include "chess/board_serializer.h"

int main()
{

    std::cout << "Hallo!! " << std::endl;

    std::string name = "Rebecca";
    chess::game::Player p1{name, chess::Color::WHITE};

    auto pawn = chess::game::Piece{chess::PieceType::PAWN, chess::Color::WHITE};
    std::tuple<int, int, chess::game::Piece> initial_piece = {0, 0, pawn};
    chess::game::Board board({initial_piece});

    while (true)
    {
        std::cout << "Enter source x: ";
        int source_x;
        std::cin >> source_x;
        std::cout << "Enter source y: ";
        int source_y;
        std::cin >> source_y;

        std::cout << "Enter destination x: ";
        int destination_x;
        std::cin >> destination_x;

        std::cout << "Enter destination y: ";
        int destination_y;
        std::cin >> destination_y;

        auto success = board.move(source_x, source_y, destination_x, destination_y);

        if (success)
        {
            std::cout << "Move successful!" << std::endl;
        }
        else
        {
            std::cout << "Move failed! Try again..." << std::endl;
        }

        std::cout << chess::ui::cmd::serialize(board) << std::endl;
    }
}