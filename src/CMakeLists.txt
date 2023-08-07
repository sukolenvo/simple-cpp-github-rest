FILE(GLOB source simple_cpp_github_rest/*.cpp)

add_library(simple-cpp-github-rest ${source})
target_link_libraries(simple-cpp-github-rest PUBLIC simple-cpp-github-rest-compiler_options CURL::libcurl glaze::glaze)
target_include_directories(simple-cpp-github-rest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/dto)

add_library(simple-cpp-github-rest::lib ALIAS simple-cpp-github-rest)