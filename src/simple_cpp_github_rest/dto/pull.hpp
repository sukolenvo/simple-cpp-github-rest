#ifndef SIMPLE_CPP_GITHUB_REST_PULL_HPP
#define SIMPLE_CPP_GITHUB_REST_PULL_HPP

#include <compare>

#include <glaze/glaze.hpp>

namespace simple_cpp::github_rest {

struct Pull
{
  unsigned long number{};
  std::strong_ordering operator<=>(const Pull &other) const = default;
};
} // namespace simple_cpp::github_rest

template<> struct glz::meta<simple_cpp::github_rest::Pull>
{
  using T = simple_cpp::github_rest::Pull;
  static constexpr auto value = object("number", &simple_cpp::github_rest::Pull::number);
};

#endif // SIMPLE_CPP_GITHUB_REST_PULL_HPP
