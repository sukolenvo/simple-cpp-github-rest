#include <string>

#include "exception.hpp"
#include "get_reference.hpp"

simple_cpp::github_rest::GetReferenceRequest::GetReferenceRequest(const std::string &ref)
{
  request.add_path_segment("git")->add_path_segment("ref")->add_path_segment(ref);
}
simple_cpp::github_rest::Reference simple_cpp::github_rest::GetReferenceRequest::execute(
  simple_cpp::github_rest::Client &client)
{
  simple_cpp::github_rest::Response response = client.get(request.build_url());
  if (response.status_code() != 200) {
    throw simple_cpp::github_rest::GithubRestApiException("Get reference", response);
  }
  simple_cpp::github_rest::Reference reference;
  auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(reference, response.get_body());
  if (err) {
    throw simple_cpp::github_rest::GithubRestParseException("Get reference", err, response);
  }
  return reference;
}
