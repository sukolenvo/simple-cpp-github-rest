#ifndef SIMPLE_CPP_GITHUB_REST_CLIENT_HPP
#define SIMPLE_CPP_GITHUB_REST_CLIENT_HPP

#include <string>

#include "response.hpp"

namespace simple_cpp::github_rest {

class Client
{
  std::string owner;
  std::string repo_name;
  std::string token;

protected:
  simple_cpp::github_rest::Response
    request_with_body(const std::string &method, const std::string &url, const std::string &body);

public:
  Client(std::string owner_, std::string repo_name_, std::string token_);

  virtual simple_cpp::github_rest::Response get(const std::string &url);

  virtual simple_cpp::github_rest::Response post(const std::string &url, const std::string &body);

  virtual simple_cpp::github_rest::Response patch(const std::string &url, const std::string &body);
};
} // namespace simple_cpp::github_rest

#endif // SIMPLE_CPP_GITHUB_REST_CLIENT_HPP
