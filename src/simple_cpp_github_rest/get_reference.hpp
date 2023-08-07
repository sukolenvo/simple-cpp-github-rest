#ifndef SIMPLE_CPP_GITHUB_REST_GET_REFERENCE_HPP
#define SIMPLE_CPP_GITHUB_REST_GET_REFERENCE_HPP

#include "client.hpp"
#include "dto/reference.hpp"
#include "request.hpp"

namespace simple_cpp::github_rest {

class GetReferenceRequest
{
  simple_cpp::github_rest::Request request;

public:
  explicit GetReferenceRequest(const std::string &ref);

  simple_cpp::github_rest::Reference execute(simple_cpp::github_rest::Client &client);
};
}

#endif // SIMPLE_CPP_GITHUB_REST_GET_REFERENCE_HPP
