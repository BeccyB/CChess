# file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE HEADER_FILES ${PROJECT_SOURCE_DIR}/*.h)


# file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp) # ${PROJECT_SOURCE_DIR}
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp) # ${PROJECT_SOURCE_DIR}

# message(STATUS "Source files found: ${SRC_FILES}")
add_library(chess STATIC
    ${HEADER_FILES}
    ${SRC_FILES}
)

set_target_properties(chess PROPERTIES LINKER_LANGUAGE CXX)

# Specify the include directories
# target_include_directories(chess PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(chess PUBLIC ${CMAKE_SOURCE_DIR})
