
add_library(chess

    include/chess/board_serializer.h
    include/chess/board.h
    include/chess/common.h
    include/chess/field.h
    include/chess/piece.h
    include/chess/player.h

    src/board_serializer.cc
    src/board.cc
    src/common.cc
    src/piece.cc
)

target_include_directories(chess PUBLIC include)