#include <string>

#include "exception.hpp"
#include "get_repository_content.hpp"

simple_cpp::github_rest::GetRepositoryContentRequest::GetRepositoryContentRequest(const std::string &path,
  const std::string &ref)
{
  request.add_path_segment("contents")->add_path_segment(path);
  request.set_query_param("ref", ref);
}

simple_cpp::github_rest::RepositoryContent simple_cpp::github_rest::GetRepositoryContentRequest::execute(
  simple_cpp::github_rest::Client &client)
{
  simple_cpp::github_rest::Response response = client.get(request.build_url());
  if (response.status_code() != 200) {
    throw simple_cpp::github_rest::GithubRestException(
      std::string("Failed to get repository content. Response code: ") + std::to_string(response.status_code()));
  }
  simple_cpp::github_rest::RepositoryContent repositoryContent;
  auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(repositoryContent, response.get_body());
  if (err) {
    throw simple_cpp::github_rest::GithubRestException(
      std::string("Failed to get repository content. Parse error: ") + glz::format_error(err, response.get_body()));
  }
  return repositoryContent;
}
