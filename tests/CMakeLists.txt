enable_testing()

file(GLOB CHESS_TESTS_INCLUDE
    ${PROJECT_SOURCE_DIR}/tests/*.cc
)

add_executable(all_tests ${CHESS_TESTS_INCLUDE})

target_link_libraries(all_tests
    PUBLIC GTest::gtest_main
)

target_link_libraries(all_tests
    PUBLIC chess
)

include(GoogleTest)
gtest_discover_tests(all_tests)