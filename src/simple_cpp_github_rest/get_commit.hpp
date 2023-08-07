#ifndef SIMPLE_CPP_GITHUB_REST_GET_COMMIT_HPP
#define SIMPLE_CPP_GITHUB_REST_GET_COMMIT_HPP

#include <string>

#include "client.hpp"
#include "dto/commit.hpp"
#include "request.hpp"

namespace simple_cpp::github_rest {

class GetCommitRequest
{
  simple_cpp::github_rest::Request request;

public:
  explicit GetCommitRequest(const std::string &commitSha);

  simple_cpp::github_rest::Commit execute(simple_cpp::github_rest::Client &client);
};
} // namespace simple_cpp::github_rest

#endif // SIMPLE_CPP_GITHUB_REST_GET_COMMIT_HPP
