#include <CChess/Piece.h>
#include <CChess/Player.h>

class Queen : public Piece {

    bool isPossibleDirection(Coordinate diff) {
        // check if direction available
        return abs(diff.x) == abs(diff.y) ||
            (diff.x == 0 && diff.y != 0) ||
            (diff.x != 0 && diff.y == 0);
    }

    bool checkMove(Coordinate destination) {
        // Compute direction vector to destination
        auto diff = destination - getPosition();

        if (!isPossibleDirection(diff)) {
            return false;
        }

        // go along direction of diff
        // until ether
        // arrives at destination -> return true
        // or there is a piece in the way -> return false
        
        return true;
    }

};