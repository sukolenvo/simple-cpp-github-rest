#ifndef SIMPLE_CPP_GITHUB_REST_UPDATE_REFERENCE_HPP
#define SIMPLE_CPP_GITHUB_REST_UPDATE_REFERENCE_HPP

#include <string>

#include <glaze/glaze.hpp>

#include "client.hpp"
#include "dto/reference.hpp"
#include "request.hpp"

namespace simple_cpp::github_rest {

struct UpdateReferenceRequestBody
{
  std::string sha;
};

class UpdateReferenceRequest
{
  simple_cpp::github_rest::Request request;
  UpdateReferenceRequestBody requestBody;
public:
  UpdateReferenceRequest(const std::string &ref, UpdateReferenceRequestBody body);

  simple_cpp::github_rest::Reference execute(simple_cpp::github_rest::Client &client);
};
}

template <>
struct glz::meta<simple_cpp::github_rest::UpdateReferenceRequestBody> {
  using T = simple_cpp::github_rest::UpdateReferenceRequestBody;
  static constexpr auto value = object(
    "sha", &simple_cpp::github_rest::UpdateReferenceRequestBody::sha
  );
};

#endif // SIMPLE_CPP_GITHUB_REST_UPDATE_REFERENCE_HPP
