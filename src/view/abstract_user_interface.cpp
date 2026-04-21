#include "abstract_user_interface.h"

#include <iostream>


void Viewer::display_game(Position_of_pawn p) {
    std::cout << "---- imaginary chess board with pawn ---- on position: (" << p.x << ", " << p.y << ")" << std::endl;  
}