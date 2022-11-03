#include <array>
#include <optional>
#include <memory>
#include <iostream>

#include "Player.h"
#include "Piece.h"

class Board {

    public:

    bool gameMove(Player& player) {

        // 1. player chooses a piece on the board
        std::optional result = std::make_optional<Piece>({});

        while (true) {

            result = startField(player);

            if (!result.has_value()) {
                std::cout << "The selected piece is not valid" << std::endl;
                continue;
            }

            auto piece = result.value();
            std::cout << "You have selected the chess piece: "<< piece.getName() << std::endl;
            
            
            // 2. player chooses destination field
            if (moveToDestination()) {
                break;
            }
        }

        return true;
    }

    std::optional<Piece> startField(Player& player) {
        
        std::string start; // "4,5"
        std::cout << "input a field id" << std::endl;
        std::cin >> start;

        int i = start.at(0); // 4 
        int j = start.at(2); // 5

        if (i < 1 || i > 8 || j < 1 || j > 8) {
            std::cout << "coordinates are invalid!" << std::endl;
            return {};
        }

        // check the board and get a pice
        auto piece = board[i][j];
        
        if (piece.has_value()) {
            // must be a pice of the right color

            if(piece.value().getColor() == player.color) {
                // selection was valid!
                // return piece;
            }
        }

        return {};
    }

    bool moveToDestination() {
        return false;
    }

    bool checkChessMate() {
        return false;
    }
    
    private:
    // empty '', white = 'wqueen', black piece {"white", "queen"}
    std::array<std::array<std::optional<Piece>, 8>, 8> board;
};