add_subdirectory(googletest)

add_executable(
  tests
  src/lexer_test.cpp
)

target_link_libraries(
  tests PRIVATE token_library lexer_library GTest::gtest_main 
)

include(GoogleTest)
gtest_discover_tests(tests)