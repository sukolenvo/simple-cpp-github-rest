#include <string>

#include "exception.hpp"
#include "get_pull.hpp"

simple_cpp::github_rest::GetPullRequest::GetPullRequest(unsigned long number)
{
  request.add_path_segment("pulls")->add_path_segment(std::to_string(number));
}

simple_cpp::github_rest::Pull simple_cpp::github_rest::GetPullRequest::execute(simple_cpp::github_rest::Client &client)
{
  simple_cpp::github_rest::Response response = client.get(request.build_url());
  if (response.status_code() != 200) {
    throw simple_cpp::github_rest::GithubRestApiException("Get pull", response);
  }
  simple_cpp::github_rest::Pull pull;
  auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(pull, response.get_body());
  if (err) {
    throw simple_cpp::github_rest::GithubRestParseException("Get pull", err, response);
  }
  return pull;
}
