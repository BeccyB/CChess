#include <gtest/gtest.h>
#include "model/board.h"
#include "model/coordinate.h"
#include "model/game_move.h"

#include <iostream>

TEST(TestPawnMove, BasicAssertions) {

    using namespace model;

    Board board;
    board.initalize_with_pawns();

    // valid start and destination

    auto s1 = Coordinate('a', "2");
    auto d1 = Coordinate('a', "3");

    model::GameMove move;
    move.set_if_valid(board, s1);
    move.set_if_valid(board, d1);

    ASSERT_TRUE(move.ready());

    auto [start, destination] = move.get();
    board.make_move(start, destination);

    ASSERT_TRUE(board.is_occupied(d1));

    move.reset();

    model::GameMove next_move;
    auto d2 = Coordinate('a', "4");

    next_move.set_if_valid(board, d1);
    next_move.set_if_valid(board, d2);

    ASSERT_TRUE(next_move.ready());

    if (next_move.ready()) {
        auto [start_next, destination_next] = next_move.get();
        board.make_move(start_next, destination_next);

        ASSERT_TRUE(board.is_occupied(destination_next));
    }
}

TEST(TestGameMove, BasicAssertions) {

    std::cout << "test game move" << std::endl;
    model::Board board;
    board.initalize_with_pawns();

    model::GameMove move;

    ASSERT_FALSE(move.ready());

    // valid start and destination
    auto status1 = move.set_if_valid(board, model::Coordinate{'b', "2"});
    ASSERT_EQ(status1, model::GameMove::ValidityStatus::VALID);

    auto status2 = move.set_if_valid(board, model::Coordinate{'c', "2"});
    ASSERT_EQ(status2, model::GameMove::ValidityStatus::VALID);
    ASSERT_TRUE(move.ready());

    model::GameMove move_invalid;

    // invalid start 2x

    auto coord = model::Coordinate{'a', "2"};
    ASSERT_FALSE(board.is_occupied(coord));
    std::cout << "is occupied " << board.is_occupied(coord) << std::endl;
    status1 = move_invalid.set_if_valid(board, coord);

    auto value =
        status1 == model::GameMove::ValidityStatus::VALID ? "VALID" : "other";
    std::cout << value << std::endl;

    ASSERT_EQ(status1, model::GameMove::ValidityStatus::VALID);

    ASSERT_FALSE(move_invalid.start.has_value());
    ASSERT_FALSE(move_invalid.destination.has_value());
    ASSERT_FALSE(move_invalid.ready());
}