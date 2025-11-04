enable_testing()

include(GoogleTest)

file(GLOB CHESS_TESTS_INCLUDE
    ${PROJECT_SOURCE_DIR}/tests/*.cc
)

add_executable(all_tests ${CHESS_TESTS_INCLUDE})

# Coverage option (default: OFF)
option(COVERAGE "Enable coverage reporting" ON)

if(COVERAGE AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Building with coverage flags")
    target_compile_options(all_tests PRIVATE -fprofile-arcs -ftest-coverage)
    target_link_libraries(all_tests PRIVATE gcov)
endif()

set(BUILD_SHARED_LIBS OFF)

target_link_libraries(all_tests
    PUBLIC GTest::gtest_main
)

target_link_libraries(all_tests
    PUBLIC chess
)

gtest_discover_tests(all_tests)

