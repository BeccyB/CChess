#include <gtest/gtest.h>
#include "controller/controller.h"
#include "model/board.h"
#include "model/field.h"

#include <iostream>

TEST(TestGame, BasicAssertions) {

    std::cout << "Test" << std::endl;

    model::Board board;

    for (const auto row : board.fields) {
        for (const auto col : row) {
            auto rest = col == 0;
        }
    }

    auto field = model::Field{'B', 2};

    std::cout << field.get_row_index() << std::endl;    // 1
    std::cout << field.get_column_index() << std::endl; // 1

    field = model::Field{'H', 5};

    std::cout << field.get_row_index() << std::endl;    // 4
    std::cout << field.get_column_index() << std::endl; // 7
}