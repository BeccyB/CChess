
add_library(CChess  ChessPiece.cc 
                    "../include/CChess/ChessPiece.h" 
                    )

target_include_directories(CChess PUBLIC ../include)