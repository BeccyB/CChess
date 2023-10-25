add_executable(chess_cmd chess_cmd.cpp)

target_compile_features(chess_cmd PUBLIC cxx_std_20)

target_link_libraries(chess_cmd PUBLIC chess)
