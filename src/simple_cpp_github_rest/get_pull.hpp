#ifndef SIMPLE_CPP_GITHUB_REST_GET_PULL_HPP
#define SIMPLE_CPP_GITHUB_REST_GET_PULL_HPP

#include "client.hpp"
#include "dto/pull.hpp"
#include "request.hpp"

namespace simple_cpp::github_rest {

class GetPullRequest
{
  simple_cpp::github_rest::Request request;

public:
  explicit GetPullRequest(unsigned long number);

  simple_cpp::github_rest::Pull execute(simple_cpp::github_rest::Client &client);
};
} // namespace simple_cpp::github_rest

#endif // SIMPLE_CPP_GITHUB_REST_GET_PULL_HPP
