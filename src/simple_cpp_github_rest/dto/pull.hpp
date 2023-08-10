#ifndef SIMPLE_CPP_GITHUB_REST_PULL_HPP
#define SIMPLE_CPP_GITHUB_REST_PULL_HPP

#include <compare>
#include <optional>

#include <glaze/glaze.hpp>

namespace simple_cpp::github_rest {

struct PullCommit
{
  std::string sha;

  std::strong_ordering operator<=>(const PullCommit &other) const = default;
};

struct Pull
{
  unsigned long number{};
  std::optional<std::string> body;
  PullCommit head;
  PullCommit base;

  std::strong_ordering operator<=>(const Pull &other) const = default;
};
} // namespace simple_cpp::github_rest

template<> struct glz::meta<simple_cpp::github_rest::PullCommit>
{
  using T = simple_cpp::github_rest::PullCommit;
  static constexpr auto value = object("sha", &simple_cpp::github_rest::PullCommit::sha);
};

template<> struct glz::meta<simple_cpp::github_rest::Pull>
{
  using T = simple_cpp::github_rest::Pull;
  static constexpr auto value = object("number",
    &simple_cpp::github_rest::Pull::number,
    "body",
    &simple_cpp::github_rest::Pull::body,
    "head",
    &simple_cpp::github_rest::Pull::head,
    "base",
    &simple_cpp::github_rest::Pull::base);
};

#endif // SIMPLE_CPP_GITHUB_REST_PULL_HPP
