#include <string>

#include "create_commit.hpp"
#include "exception.hpp"

simple_cpp::github_rest::CreateCommitRequest::CreateCommitRequest(simple_cpp::github_rest::CreateCommitRequestBody body)
  : requestBody(std::move(body))
{
  request.add_path_segment("git")->add_path_segment("commits");
}

simple_cpp::github_rest::Commit simple_cpp::github_rest::CreateCommitRequest::execute(
  simple_cpp::github_rest::Client &client)
{
  std::string json = glz::write_json(requestBody);
  simple_cpp::github_rest::Response response = client.post(request.build_url(), json);
  if (response.status_code() != 201) {
    throw simple_cpp::github_rest::GithubRestApiException("Create commit", response);
  }
  simple_cpp::github_rest::Commit commit;
  auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(commit, response.get_body());
  if (err) {
    throw simple_cpp::github_rest::GithubRestParseException("Create commit", err, response);
  }
  return commit;
}
