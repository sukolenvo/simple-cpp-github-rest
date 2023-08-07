#ifndef SIMPLE_CPP_GITHUB_REST_CREATE_REFERENCE_HPP
#define SIMPLE_CPP_GITHUB_REST_CREATE_REFERENCE_HPP

#include <string>

#include <glaze/glaze.hpp>

#include "client.hpp"
#include "dto/reference.hpp"
#include "request.hpp"

namespace simple_cpp::github_rest {

struct CreateReferenceRequestBody
{
  std::string ref;
  std::string sha;
};

class CreateReferenceRequest
{
  simple_cpp::github_rest::Request request;
  CreateReferenceRequestBody requestBody;

public:
  explicit CreateReferenceRequest(CreateReferenceRequestBody body);

  simple_cpp::github_rest::Reference execute(simple_cpp::github_rest::Client &client);
};
} // namespace simple_cpp::github_rest

template<> struct glz::meta<simple_cpp::github_rest::CreateReferenceRequestBody>
{
  using T = simple_cpp::github_rest::CreateReferenceRequestBody;
  static constexpr auto value = object("ref",
    &simple_cpp::github_rest::CreateReferenceRequestBody::ref,
    "sha",
    &simple_cpp::github_rest::CreateReferenceRequestBody::sha);
};

#endif // SIMPLE_CPP_GITHUB_REST_CREATE_REFERENCE_HPP
