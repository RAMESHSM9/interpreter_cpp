set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
	interpreter
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(
	interpreter PRIVATE lexer_library token_library repl
)

add_subdirectory(token)
add_subdirectory(lexer)
add_subdirectory(repl)

