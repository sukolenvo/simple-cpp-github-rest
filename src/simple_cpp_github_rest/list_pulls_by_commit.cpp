#include <string>

#include <glaze/glaze.hpp>

#include "exception.hpp"
#include "list_pulls_by_commit.hpp"

static const int PAGE_SIZE = 30;

simple_cpp::github_rest::ListPullsByCommitRequest::ListPullsByCommitRequest(const std::string &commitSha)
{
  request.add_path_segment("commits")->add_path_segment(commitSha)->add_path_segment("pulls");
  request.set_query_param("per_page", std::to_string(PAGE_SIZE));
}

std::vector<simple_cpp::github_rest::Pull> simple_cpp::github_rest::ListPullsByCommitRequest::execute(
  simple_cpp::github_rest::Client &client)
{
  request.set_query_param("page", "1");
  simple_cpp::github_rest::Response response = client.get(request.build_url());
  if (response.status_code() != 200) {
    throw simple_cpp::github_rest::GithubRestApiException("List pulls by commit", response);
  }
  std::vector<simple_cpp::github_rest::Pull> result;
  static const int MAX_PAGES = 100;
  for (int i = 0; i < MAX_PAGES; ++i) {
    request.set_query_param("page", std::to_string(i + 1));
    std::vector<simple_cpp::github_rest::Pull> chunk;
    auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(chunk, response.get_body());
    if (err) {
      throw simple_cpp::github_rest::GithubRestParseException("List pulls by commit", err, response);
    }
    result.insert(result.end(), chunk.begin(), chunk.end());
    if (chunk.size() != PAGE_SIZE) {
      break;
    }
  }
  return result;
}
