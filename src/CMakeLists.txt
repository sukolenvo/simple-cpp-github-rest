FILE(GLOB source simple_cpp_github_rest/*.cpp simple_cpp_github_rest/dto/*.cpp)

add_library(simple-cpp-github-rest ${source})
target_link_libraries(simple-cpp-github-rest PRIVATE simple-cpp-github-rest-compiler_options CURL::libcurl simple-cpp-base64::lib)
target_link_libraries(simple-cpp-github-rest PUBLIC glaze::glaze) # TODO can this be private?
target_include_directories(simple-cpp-github-rest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/dto)

add_library(simple-cpp-github-rest::lib ALIAS simple-cpp-github-rest)