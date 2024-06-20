add_executable(simpleChess simpleChess.cpp)
target_compile_features(simpleChess PUBLIC cxx_std_17)
target_link_libraries(simpleChess PUBLIC CChess)


# executable
add_executable(main main.cpp)
target_compile_features(main PUBLIC cxx_std_17)
# TODO link libraries