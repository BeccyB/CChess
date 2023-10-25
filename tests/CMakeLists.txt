enable_testing()

add_executable(all_tests test_board.cc)

target_link_libraries(all_tests
    PUBLIC GTest::gtest_main
)

target_link_libraries(all_tests
    PUBLIC chess
)

include(GoogleTest)
gtest_discover_tests(all_tests)