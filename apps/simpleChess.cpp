#include <iostream>
#include <vector>
#include <array>

#include <CChess/Board.h>
#include <CChess/Player.h>


// class Board; // contains pieces, board
// class Player;

int main () {

    std::cout << "Hallo!!";

    /*

        - chess board
            - array 8 x 8 = 64 
            
            
            - std::map<string,ChessPiece> pices = {'wd': whiteDame(),  };
            - std::array<string> borad; 5,1 = 'WD'

        struct Field { ChessPiece = ptr }; 

        std::erase(iterPice);

        - Chess Pieces:  

            - different types: 
                - pawn x 8
                - Casle (Rook) x 2 
                - Bishop x 2
                - Knight x 2 
                - Dame x 1
                - king x 1  (not allowed to move to square where he can be taken)

            - unique traits: 
                colour (b/w), 
                string: 'Bishop', 'Dame'  'Knight', 'King',
                bool alive = true;

                isAlive()  { return alive }

            // result: changes the position 
            - virtual move() {

                 

                if (destination is valid) {
                    make move ..
                    return
                }

                "Ilegal move!"
            }

            - move types (diagonal, horizontal, L-shape), möglichkeits raum (reach),

        - Player: 

            - name
            - moveHistory = vector<string>('F2F4');

        - Main () {

            players = [white, black];

            // game loop 
            while (noSurender && is_mate) {
            
                for (player in players)  {

                    cout << "select a peace"
                    
                    int 
                    1. cin >> "F12"

                    try {
                        auto chessPiece = getPiece("F12");
                    } catch (exception) {
                        // no chess pice was found
                        // go back to 
                    }
                    
                    
                    if (chessPiece == nullptr)


                    move()

                }

                is_mate = checkChessMate() // king has no valid move

            }   
        }
    
    */

    // Board board;
    Player white;
    Player black;
    std::array<Player,2> players = {white, black};

    bool noSurender = true;
    bool notCheckMate = true;

    int playIndex = 0;

    /* 
    while (noSurender && notCheckMate) {

        bool made_move = false;
        auto current = players.at(playIndex);

        while (!made_move)  {

            try {
                made_move = board.gameMove(current);
            } catch (std::runtime_error & error) {
                // TODO 
            }

        }

        notCheckMate = board.checkChessMate(); // king has no valid move
        
        playIndex = (playIndex + 1)%2;
    }   */
    
}