#ifndef SIMPLE_CPP_GITHUB_REST_REFERENCE_HPP
#define SIMPLE_CPP_GITHUB_REST_REFERENCE_HPP

#include <string>

#include <glaze/glaze.hpp>

namespace simple_cpp::github_rest {

struct ObjectRef
{
  std::string sha;
  std::string type;
};

struct Reference
{
  ObjectRef object;
};
} // namespace simple_cpp::github_rest

template<> struct glz::meta<simple_cpp::github_rest::ObjectRef>
{
  using T = simple_cpp::github_rest::ObjectRef;
  static constexpr auto value =
    object("sha", &simple_cpp::github_rest::ObjectRef::sha, "type", &simple_cpp::github_rest::ObjectRef::type);
};

template<> struct glz::meta<simple_cpp::github_rest::Reference>
{
  using T = simple_cpp::github_rest::Reference;
  static constexpr auto value = object("object", &simple_cpp::github_rest::Reference::object);
};

#endif // SIMPLE_CPP_GITHUB_REST_REFERENCE_HPP
