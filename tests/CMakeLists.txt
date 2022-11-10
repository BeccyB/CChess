enable_testing()

add_executable(test_make_move test_make_move.cc)

target_link_libraries(test_make_move
PUBLIC GTest::gtest_main
)

target_link_libraries(test_make_move
PUBLIC CChess
)

include(GoogleTest)
gtest_discover_tests(test_make_move)