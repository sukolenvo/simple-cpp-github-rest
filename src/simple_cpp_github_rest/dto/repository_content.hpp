#ifndef SIMPLE_CPP_GITHUB_REST_REPOSITORY_CONTENT_HPP
#define SIMPLE_CPP_GITHUB_REST_REPOSITORY_CONTENT_HPP

#include <string>

#include <glaze/glaze.hpp>

namespace simple_cpp::github_rest {

struct RepositoryContent
{
  std::string type;
  std::string encoding;
  std::string content;

  std::string parse_content() const;
};
} // namespace simple_cpp::github_rest

template<> struct glz::meta<simple_cpp::github_rest::RepositoryContent>
{
  using T = simple_cpp::github_rest::RepositoryContent;
  static constexpr auto value = object("type",
    &simple_cpp::github_rest::RepositoryContent::type,
    "encoding",
    &simple_cpp::github_rest::RepositoryContent::encoding,
    "content",
    &simple_cpp::github_rest::RepositoryContent::content);
};


#endif // SIMPLE_CPP_GITHUB_REST_REPOSITORY_CONTENT_HPP
