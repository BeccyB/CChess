#include <array>
#include <optional>
#include <memory>
#include "ChessPiece.h"

struct Field {
        ChessPiece piece;
        bool isOccupied;
};

class ChessBoard {

    public:

    bool gameMove(Player& player) {

        // 1. player chooses a piece on the board
        std::optional result = std::make_optional<Field>({});

        while (true) {

            result = startField(player);

            if (!result.has_value()) {
                std::cout << "The selected piece is not valid" << std::endl;
                continue;
            }

            auto field = result.value();
            std::cout << "You have selected the chess piece: "<< field.piece.name << std::endl;
            
            
            // 2. player chooses destination field
            if (moveToDestination(field)) {
                break;
            }
        }


    }

    std::optional<Field&> startField(Player& player) {
        
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
        auto& field = board[i][j];
        
        if (field.isOccupied) {
            // must be a pice of the right color

            if(field.piece.color == player.color) {
                // selection was valid!
                return field;
            }
        }

        return {};
    }

    bool moveToDestination(Field& field) {
        /* if (movePossible) {

            return true;
        }*/

        return false;
    }

    bool checkChessMate() {
        // TODO
        return false;
    }
    
    private:
    // empty '', white = 'wqueen', black piece {"white", "queen"}
    std::array<std::array<Field, 8>, 8> board;
};