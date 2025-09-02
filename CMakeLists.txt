cmake_minimum_required(VERSION 3.22.1)

project(Chess)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# code coverage analysis
IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
        # enable extensive debug output
        OPTION(DEBUG_EXTENSIVE "Switch on extensive debug output" OFF)
        OPTION(CHESS_ENABLE_COVERAGE "Enable GCov coverage analysis (defines a 'coverage' target and enforces static build of CHESS)" OFF)
        IF(CHESS_ENABLE_COVERAGE)
                MESSAGE(STATUS "Coverage enabled")
                INCLUDE(CodeCoverage)
                setup_code_coverage(coverage-cobertura all_tests coverage $ENV{COVERAGE_ARGS})
        ELSE()
                MESSAGE(STATUS "Coverage disabled")
        ENDIF()
ENDIF()

add_subdirectory(src)
add_subdirectory(apps)
add_subdirectory(tests)

