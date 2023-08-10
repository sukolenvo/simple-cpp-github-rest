#include "exception.hpp"

simple_cpp::github_rest::GithubRestException::GithubRestException(std::string details) : message(std::move(details))
{}

const char *simple_cpp::github_rest::GithubRestException::what() const noexcept
{
  return message.c_str();
}

simple_cpp::github_rest::GithubRestApiException::GithubRestApiException(const std::string &operation,
  const simple_cpp::github_rest::Response &response)
  : GithubRestException(
    operation + " failed. Response: " + std::to_string(response.status_code()) + "\n" + response.get_body())
{}

simple_cpp::github_rest::GithubRestParseException::GithubRestParseException(const std::string &operation,
  const glz::parse_error &error,
  const Response &response)
  : GithubRestException(operation + " failed. Error: " + glz::format_error(error, response.get_body()))
{}
