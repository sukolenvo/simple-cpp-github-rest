#include "get_commit.hpp"

simple_cpp::github_rest::GetCommitRequest::GetCommitRequest(const std::string &commitSha)
{
  request.add_path_segment("git")->add_path_segment("commits")->add_path_segment(commitSha);
}
simple_cpp::github_rest::Commit simple_cpp::github_rest::GetCommitRequest::execute(
  simple_cpp::github_rest::Client &client)
{
  simple_cpp::github_rest::Response response = client.get(request.build_url());
  if (response.status_code() != 200) {
    throw "unexpected response code";
  }
  simple_cpp::github_rest::Commit commit;
  auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(commit, response.get_body());
  if (err) {
    throw std::runtime_error(glz::format_error(err, response.get_body()));
  }
  return commit;
}
