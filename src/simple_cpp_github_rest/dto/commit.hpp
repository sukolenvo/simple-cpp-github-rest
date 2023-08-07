#ifndef SIMPLE_CPP_GITHUB_REST_COMMIT_HPP
#define SIMPLE_CPP_GITHUB_REST_COMMIT_HPP

#include <glaze/glaze.hpp>

namespace simple_cpp::github_rest {

struct TreeRef
{
  std::string sha;
};

struct Commit
{
  std::string sha;
  TreeRef tree;
};
} // namespace simple_cpp::github_rest

template<> struct glz::meta<simple_cpp::github_rest::TreeRef>
{
  using T = simple_cpp::github_rest::TreeRef;
  static constexpr auto value = object("sha", &simple_cpp::github_rest::TreeRef::sha);
};

template<> struct glz::meta<simple_cpp::github_rest::Commit>
{
  using T = simple_cpp::github_rest::Commit;
  static constexpr auto value =
    object("sha", &simple_cpp::github_rest::Commit::sha, "tree", &simple_cpp::github_rest::Commit::tree);
};

#endif // SIMPLE_CPP_GITHUB_REST_COMMIT_HPP
