#ifndef SIMPLE_CPP_GITHUB_REST_EXCEPTION_HPP
#define SIMPLE_CPP_GITHUB_REST_EXCEPTION_HPP

#include <exception>
#include <string>

namespace simple_cpp::github_rest {

class GithubRestException : public std::exception
{
  std::string message;

public:
  explicit GithubRestException(std::string details);
  const char *what() const noexcept override;
};
} // namespace simple_cpp::github_rest

#endif // SIMPLE_CPP_GITHUB_REST_EXCEPTION_HPP
