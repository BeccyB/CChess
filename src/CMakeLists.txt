
add_library(CChess  Piece.cc
                    Queen.cc

                    "../include/CChess/Board.h"
                    "../include/CChess/Coordinate.h"
                    "../include/CChess/Piece.h"
                    "../include/CChess/Player.h"
                    "../include/CChess/Queen.h" 

                    )

target_include_directories(CChess PUBLIC ../include)