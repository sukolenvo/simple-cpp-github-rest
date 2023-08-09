#ifndef SIMPLE_CPP_GITHUB_REST_UPDATE_PULL_HPP
#define SIMPLE_CPP_GITHUB_REST_UPDATE_PULL_HPP

#include <string>

#include <glaze/glaze.hpp>

#include "client.hpp"
#include "dto/pull.hpp"
#include "request.hpp"

namespace simple_cpp::github_rest {

struct UpdatePullRequestBody
{
  std::string body;
};

class UpdatePullRequest
{
  simple_cpp::github_rest::Request request;
  UpdatePullRequestBody requestBody;

public:
  UpdatePullRequest(unsigned long pullNumber, UpdatePullRequestBody body);

  simple_cpp::github_rest::Pull execute(simple_cpp::github_rest::Client &client);
};
} // namespace simple_cpp::github_rest

template<> struct glz::meta<simple_cpp::github_rest::UpdatePullRequestBody>
{
  using T = simple_cpp::github_rest::UpdatePullRequestBody;
  static constexpr auto value = object("body", &simple_cpp::github_rest::UpdatePullRequestBody::body);
};

#endif // SIMPLE_CPP_GITHUB_REST_UPDATE_PULL_HPP
