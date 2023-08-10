#ifndef SIMPLE_CPP_GITHUB_REST_EXCEPTION_HPP
#define SIMPLE_CPP_GITHUB_REST_EXCEPTION_HPP

#include <exception>
#include <string>

#include <glaze/glaze.hpp>

#include "response.hpp"

namespace simple_cpp::github_rest {

class GithubRestException : public std::exception
{
  std::string message;

public:
  explicit GithubRestException(std::string details);
  const char *what() const noexcept override;
};

class GithubRestParseException : public GithubRestException
{
public:
  GithubRestParseException(const std::string &operation, const glz::parse_error &error, const Response &response);
};

class GithubRestApiException : public GithubRestException
{
public:
  GithubRestApiException(const std::string &operation, const Response &response);
};
} // namespace simple_cpp::github_rest

#endif // SIMPLE_CPP_GITHUB_REST_EXCEPTION_HPP
