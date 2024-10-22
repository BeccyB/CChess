

file(GLOB CHESS_INCLUDE
    ${PROJECT_SOURCE_DIR}/include/*.h
)

file(GLOB CHESS_SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(chess ${CHESS_SRC} ${CHESS_INCLUDE})

target_include_directories(chess PUBLIC ${PROJECT_SOURCE_DIR}/include)