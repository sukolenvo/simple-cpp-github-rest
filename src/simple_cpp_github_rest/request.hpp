#ifndef SIMPLE_CPP_GITHUB_REST_REQUEST_HPP
#define SIMPLE_CPP_GITHUB_REST_REQUEST_HPP

#include <string>
#include <unordered_map>

namespace simple_cpp::github_rest {

class Request
{
  std::string path;
  std::unordered_map<std::string, std::string> queryParams;

public:
  std::string build_url() const;

  // TODO varargs
  simple_cpp::github_rest::Request *add_path_segment(const std::string &segment);
  simple_cpp::github_rest::Request *set_query_param(std::string key, std::string value);

};
} // namespace simple_cpp::github_rest

#endif // SIMPLE_CPP_GITHUB_REST_REQUEST_HPP
