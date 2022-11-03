#ifndef CCHESS_COORDINATE_H
#define CCHESS_COORDINATE_H

struct Coordinate { 
    int x;
    int y;

    Coordinate operator-(const Coordinate& other) {
        return Coordinate{x - other.x,  y - other.y}; 
    }

};

#endif