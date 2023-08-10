#include <string>

#include "exception.hpp"
#include "update_pull.hpp"

simple_cpp::github_rest::UpdatePullRequest::UpdatePullRequest(unsigned long pullNumber,
  simple_cpp::github_rest::UpdatePullRequestBody body)
  : requestBody(std::move(body))
{
  request.add_path_segment("pulls")->add_path_segment(std::to_string(pullNumber));
}

simple_cpp::github_rest::Pull simple_cpp::github_rest::UpdatePullRequest::execute(
  simple_cpp::github_rest::Client &client)
{
  std::string json = glz::write_json(requestBody);
  simple_cpp::github_rest::Response response = client.patch(request.build_url(), json);
  if (response.status_code() != 200) {
    throw simple_cpp::github_rest::GithubRestApiException("Update pull", response);
  }
  simple_cpp::github_rest::Pull pull;
  auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(pull, response.get_body());
  if (err) {
    throw simple_cpp::github_rest::GithubRestParseException("Update pull", err, response);
  }
  return pull;
}
