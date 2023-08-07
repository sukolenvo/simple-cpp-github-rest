#ifndef SIMPLE_CPP_GITHUB_REST_RESPONSE_HPP
#define SIMPLE_CPP_GITHUB_REST_RESPONSE_HPP

#include <string>

namespace simple_cpp::github_rest {

class Response
{
  long code;
  std::string body;
public:
  Response(long code_, std::string body_) : code(code_), body(std::move(body_))
  {}
  long status_code() const {
    return code;
  }
  std::string get_body() const {
    return body;
  }
};
} // namespace simple_cpp::github_rest

#endif // SIMPLE_CPP_GITHUB_REST_RESPONSE_HPP
