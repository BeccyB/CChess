#pragma once

class Controller {
  public:
    int add(int a, int b) { 
        return a + b;
    }

    int divide(int a, int b) {

        if (b == 0) {
            return 0;
        }

        return a / b;
    }
};


