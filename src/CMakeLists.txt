file(GLOB_RECURSE HEADER_FILES ${PROJECT_SOURCE_DIR}/*.h)
#message(STATUS "Header files found: ${HEADER_FILES}")

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
#message(STATUS "Source files found: ${SRC_FILES}")

add_library(chess STATIC 
    ${HEADER_FILES} 
    ${SRC_FILES}
)

# Specify the include directories
target_include_directories(chess PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
