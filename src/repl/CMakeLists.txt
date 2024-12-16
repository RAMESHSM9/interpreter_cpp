set(SOURCES
src/repl.cpp)

add_library(repl STATIC ${SOURCES})

target_include_directories(repl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(
	repl PRIVATE  lexer_library token_library
)