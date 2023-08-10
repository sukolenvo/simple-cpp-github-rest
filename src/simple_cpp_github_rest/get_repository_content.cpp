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
    throw simple_cpp::github_rest::GithubRestApiException("Get repository content", response);
  }
  simple_cpp::github_rest::RepositoryContent repositoryContent;
  auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(repositoryContent, response.get_body());
  if (err) {
    throw simple_cpp::github_rest::GithubRestParseException("Get repository content", err, response);
  }
  return repositoryContent;
}
