#include "request.hpp"

std::string simple_cpp::github_rest::Request::build_url() const
{
  std::string result{ path };
  if (!queryParams.empty()) {
    auto prefix = '?';
    for (const auto &[key, value] : queryParams) {
      result += prefix;
      result += key;
      result += "=";
      // TODO escape with https://curl.se/libcurl/c/curl_easy_escape.html
      result += value;
      prefix = '&';
    }
  }
  return result;
}

simple_cpp::github_rest::Request *simple_cpp::github_rest::Request::add_path_segment(const std::string &segment)
{
  path += "/";
  path += segment;
  return this;
}

simple_cpp::github_rest::Request *simple_cpp::github_rest::Request::set_query_param(std::string key, std::string value)
{
  for (auto &[k, v] : queryParams) {
    if (k == key) {
      v = value;
      return this;
    }
  }
  queryParams.emplace_back(std::move(key), std::move(value));
  return this;
}