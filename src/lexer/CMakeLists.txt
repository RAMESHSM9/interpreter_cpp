set(SOURCES
src/lexer.cpp)

add_library(lexer_library STATIC ${SOURCES})

target_include_directories(lexer_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(
	lexer_library PRIVATE token_library
)