#ifndef SIMPLE_CPP_GITHUB_REST_TREE_HPP
#define SIMPLE_CPP_GITHUB_REST_TREE_HPP

#include <string>
#include <vector>

#include <glaze/glaze.hpp>

namespace simple_cpp::github_rest {

struct Tree
{
  std::string sha;
};
} // namespace simple_cpp::github_rest

template<> struct glz::meta<simple_cpp::github_rest::Tree>
{
  using T = simple_cpp::github_rest::Tree;
  static constexpr auto value = object(
    "sha", &simple_cpp::github_rest::Tree::sha
    );
};

#endif // SIMPLE_CPP_GITHUB_REST_TREE_HPP
