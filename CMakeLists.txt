cmake_minimum_required(VERSION 3.26)

project(simple-cpp-github-rest VERSION 0.2 LANGUAGES CXX C)

option(SIMPLE_CPP_GITHUB_REST_WARNINGS_AS_ERRORS "Treat compiler warnings as errors")
add_library(simple-cpp-github-rest-compiler_options INTERFACE)
target_compile_features(simple-cpp-github-rest-compiler_options INTERFACE cxx_std_20)
if (MSVC)
  target_compile_options(simple-cpp-github-rest-compiler_options INTERFACE /W4 /DNOMINMAX)
  if (SIMPLE_CPP_GITHUB_REST_WARNINGS_AS_ERRORS)
    target_compile_options(simple-cpp-github-rest-compiler_options INTERFACE /WX)
  endif ()
else ()
  target_compile_options(simple-cpp-github-rest-compiler_options INTERFACE -Wall -Wextra -Wpedantic)
  if (SIMPLE_CPP_GITHUB_REST_WARNINGS_AS_ERRORS)
    target_compile_options(simple-cpp-github-rest-compiler_options INTERFACE -Werror)
  endif ()
endif ()

include(FetchContent)
FetchContent_Declare(
    curl
    GIT_REPOSITORY https://github.com/curl/curl.git
    GIT_TAG curl-8_2_1
    GIT_SHALLOW TRUE
)
FetchContent_Declare(
    glaze
    GIT_REPOSITORY https://github.com/stephenberry/glaze.git
    GIT_TAG v1.3.5
    GIT_SHALLOW TRUE
)
FetchContent_Declare(
    base64
    GIT_REPOSITORY https://github.com/sukolenvo/simple-cpp-base64.git
    GIT_TAG v1.0.1
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(curl glaze base64)

add_subdirectory(src)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  enable_testing()
  FetchContent_Declare(
      Catch2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG v3.4.0
      GIT_SHALLOW TRUE
  )
  FetchContent_MakeAvailable(Catch2)
  add_subdirectory(test)
  include(CTest)
endif ()
