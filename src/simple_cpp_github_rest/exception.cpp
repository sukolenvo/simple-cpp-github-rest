#include "exception.hpp"

simple_cpp::github_rest::GithubRestException::GithubRestException(std::string details) : message(std::move(details))
{}

const char *simple_cpp::github_rest::GithubRestException::what() const noexcept
{
  return message.c_str();
}
