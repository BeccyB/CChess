#ifndef CCHESS_PIECE_H
#define CCHESS_PIECE_H

#include <string>

#include <CChess/Coordinate.h>

class Piece {

    public:

    virtual bool checkMove(Coordinate destination);

    std::string getColor() {return color;};
    std::string getName() {return name;};
    Coordinate getPosition() {return position;};

    private:

    std::string color;
    std::string name;
    Coordinate position;

};

#endif 
