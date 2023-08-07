#include "create_commit.hpp"

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
    throw "unexpected response code";
  }
  simple_cpp::github_rest::Commit commit;
  auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(commit, response.get_body());
  if (err) {
    throw std::runtime_error(glz::format_error(err, response.get_body()));
  }
  return commit;
}
