add_executable(simpleChess simpleChess.cpp)

target_compile_features(simpleChess PUBLIC cxx_std_17)

target_link_libraries(simpleChess PUBLIC CChess)