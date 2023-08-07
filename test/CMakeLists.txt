file(GLOB test_source *.cpp)
add_executable(simple-cpp-github-rest-tests ${test_source})
target_link_libraries(simple-cpp-github-rest-tests PRIVATE Catch2::Catch2WithMain simple-cpp-github-rest-compiler_options simple-cpp-github-rest)

include(Catch)
catch_discover_tests(simple-cpp-github-rest-tests)
add_custom_command(TARGET simple-cpp-github-rest-tests POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)