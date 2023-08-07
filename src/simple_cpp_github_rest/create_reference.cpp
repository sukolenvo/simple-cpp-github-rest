#include "create_reference.hpp"

simple_cpp::github_rest::CreateReferenceRequest::CreateReferenceRequest(
  simple_cpp::github_rest::CreateReferenceRequestBody body) : requestBody(std::move(body))
{
  request.add_path_segment("git")->add_path_segment("refs");
}

simple_cpp::github_rest::Reference simple_cpp::github_rest::CreateReferenceRequest::execute(
  simple_cpp::github_rest::Client &client)
{
  std::string json = glz::write_json(requestBody);
  simple_cpp::github_rest::Response response = client.post(request.build_url(), json);
  if (response.status_code() != 201) {
    throw "unexpected response code";
  }
  simple_cpp::github_rest::Reference reference;
  auto err = glz::read<glz::opts{ .error_on_unknown_keys = false }>(reference, response.get_body());
  if (err) {
    throw std::runtime_error(glz::format_error(err, response.get_body()));
  }
  return reference;
}
