#include <iostream>
#include "controller/controller.h"

int main() {

    Controller controller;

    controller.run();

    // NEXT TIME
    // still a bug if e.g. one unselects and then selects something correct!
    // give feed back if wrong selection or if unselection is made!!!
    // clean up
    // check for const correctness of member methods that do not change the
    // status!

    return 0;
}