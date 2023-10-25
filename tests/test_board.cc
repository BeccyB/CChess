#include <gtest/gtest.h>

#include "chess/board.h"
#include "chess/common.h"

TEST(TestBoard, BoardConstructor)
{
  using chess::Color;
  using chess::PieceType;
  using chess::game::Board;

  auto pawn = chess::game::Piece{PieceType::PAWN, Color::WHITE};
  std::tuple<int, int, chess::game::Piece> single_position = {0, 0, pawn};
  Board board({single_position});

  /*EXPECT(board.at(0, 0).has_value())
  EXPECT_EQ(board.at(0, 0).value().color_, chess::game::Color::WHITE);
  EXPECT_EQ(board.at(0, 0).value().type_, chess::game::PieceType::PAWN);*/

  // prototype functions
  // 1. create board with single pawn
  // 2. move pawn from free field to free field

  // board functions
  // store current positions of pieces -> map
  // initialize pieces

  // move piece from position to free destination -> move()
  // check if there is a piece at given position -> is_free() or/and is_occupied()
  // check if given coordinates are within board bounds
  // move piece from position to occupied destination and move other piece to taken_pieces_; -> take()
  // check fields between start and stop along direction vector is free (multiple vectors and start/stop)

  // In future: record chess moves
}