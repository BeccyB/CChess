#include <iostream>
#include "src/controller/controller.h"
#include "src/model/chessgame.h"
#include "src/view/abstract_user_interface.h"

int main() {
    Controller c;

    c.run_game();

    return 0;
}