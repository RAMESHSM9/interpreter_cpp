set(SOURCES
src/token.cpp)

add_library(token_library STATIC ${SOURCES})

target_include_directories(token_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)