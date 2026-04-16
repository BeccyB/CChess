cmake_minimum_required(VERSION 3.22.1)

project(Chess)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
include(FetchContent)
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.2.1  # or latest stable
)
FetchContent_MakeAvailable(fmt)

IF (CHESS_BUILD_TESTS)
        include(FetchContent)
        FetchContent_Declare(googletest
            GIT_REPOSITORY      https://github.com/google/googletest.git
            GIT_TAG             v1.16.0)
        FetchContent_GetProperties(googletest)
        if(NOT googletest_POPULATED)
            FetchContent_Populate(googletest)
            set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE BOOL "")
            add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
            unset(CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
        endif()
ENDIF()

# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# FetchContent_MakeAvailable(googletest)

# code coverage analysis
IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
        # enable extensive debug output
        OPTION(DEBUG_EXTENSIVE "Switch on extensive debug output" OFF)
        OPTION(CHESS_ENABLE_COVERAGE "Enable GCov coverage analysis (defines a 'coverage' target and enforces static build of CHESS)" OFF)
        IF(CHESS_ENABLE_COVERAGE)
                MESSAGE(STATUS "Coverage enabled")
                INCLUDE(CodeCoverage)
                setup_code_coverage(coverage_all_tests all_tests coverage $ENV{COVERAGE_ARGS})
        ELSE()
                MESSAGE(STATUS "Coverage disabled")
        ENDIF()
ENDIF()

add_subdirectory(src)
add_subdirectory(apps)

option(CHESS_BUILD_TESTS "Build Chess testsuit" OFF)

if(CHESS_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif(CHESS_BUILD_TESTS)
