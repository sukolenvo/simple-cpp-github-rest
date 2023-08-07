#ifndef SIMPLE_CPP_GITHUB_REST_LIST_PULLS_BY_COMMIT_HPP
#define SIMPLE_CPP_GITHUB_REST_LIST_PULLS_BY_COMMIT_HPP

#include <vector>

#include "client.hpp"
#include "dto/pull.hpp"
#include "request.hpp"

namespace simple_cpp::github_rest {

class ListPullsByCommitRequest
{
  simple_cpp::github_rest::Request request;

public:
  ListPullsByCommitRequest(const std::string &commitSha);

  std::vector<simple_cpp::github_rest::Pull> execute(simple_cpp::github_rest::Client &client);
};

} // namespace simple_cpp::github_rest
#endif // SIMPLE_CPP_GITHUB_REST_LIST_PULLS_BY_COMMIT_HPP
