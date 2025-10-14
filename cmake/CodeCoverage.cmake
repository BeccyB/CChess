OPTION(CHESS_COVERAGE_GENHTML "Use Genhtml to generate htmls from gcov output" OFF)

FIND_PROGRAM(GCOVR_PATH gcovr)
FIND_PROGRAM(GCOV_PATH gcov)

IF(NOT GCOV_PATH)
    MESSAGE(FATAL_ERROR "gcov not found! Aborting...")
ENDIF()

IF(NOT CMAKE_COMPILER_IS_GNUCXX AND NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    MESSAGE(FATAL_ERROR "Compiler is not GNU gcc or clang! Aborting...")
ENDIF()

# Would only seting O0
IF(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    MESSAGE(WARNING "Code coverage results with an optimised (non-Debug) build may be misleading")
ENDIF()

# Setup compiler options
IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_DEFINITIONS(-fprofile-arcs -ftest-coverage)
    LINK_LIBRARIES(gcov)
ENDIF()

function(setup_code_coverage _targetname _testrunner _outputname)
    IF(NOT GCOVR_PATH)
        MESSAGE(FATAL_ERROR "gcovr not found! Aborting...")
    ENDIF() # NOT GCOVR_PATH

    ADD_CUSTOM_TARGET(${_targetname}
        # Run tests
        COMMAND ${_testrunner} ${ARGV3} # TODO: find out what this is
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests
        COMMENT "Running coverage tests."
    )
    ADD_CUSTOM_COMMAND(TARGET ${_targetname} POST_BUILD
        # Running gcovr with pretty-printed XML output to console
        COMMAND ${GCOVR_PATH} --xml-pretty -r ${CMAKE_SOURCE_DIR} -e '${CMAKE_SOURCE_DIR}/tests' -e '${CMAKE_SOURCE_DIR}/build/' -s
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running gcovr to produce pretty-printed XML code coverage report. ${_testrunner} ${ARGV3}"
    )

endfunction()