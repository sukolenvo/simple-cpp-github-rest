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
    throw "unexpected response code";
  }
  simple_cpp::github_rest::RepositoryContent repositoryContent;
  auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(repositoryContent, response.get_body());
  if (err) {
    throw std::runtime_error(glz::format_error(err, response.get_body()));
  }
  return repositoryContent;
}
