#include <string>

#include "create_tree.hpp"
#include "exception.hpp"

simple_cpp::github_rest::CreateTreeRequest::CreateTreeRequest(simple_cpp::github_rest::CreateTreeRequestBody body)
  : requestBody(std::move(body))
{
  request.add_path_segment("git")->add_path_segment("trees");
}

simple_cpp::github_rest::Tree simple_cpp::github_rest::CreateTreeRequest::execute(
  simple_cpp::github_rest::Client &client)
{
  std::string json = glz::write_json(requestBody);
  simple_cpp::github_rest::Response response = client.post(request.build_url(), json);
  if (response.status_code() != 201) {
    throw simple_cpp::github_rest::GithubRestException(
      std::string("Failed to create tree. Response code: ") + std::to_string(response.status_code()));
  }
  simple_cpp::github_rest::Tree tree;
  auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(tree, response.get_body());
  if (err) {
    throw simple_cpp::github_rest::GithubRestException(
      std::string("Failed to create tree. Parse error: ") + glz::format_error(err, response.get_body()));
  }
  return tree;
}
