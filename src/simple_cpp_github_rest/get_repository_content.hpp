#ifndef SIMPLE_CPP_GITHUB_REST_GET_REPOSITORY_CONTENT_HPP
#define SIMPLE_CPP_GITHUB_REST_GET_REPOSITORY_CONTENT_HPP

#include <string>

#include "client.hpp"
#include "dto/repository_content.hpp"
#include "request.hpp"

namespace simple_cpp::github_rest
{

class GetRepositoryContentRequest
{
  simple_cpp::github_rest::Request request;
public:
  GetRepositoryContentRequest(const std::string &path, const std::string &ref);

  simple_cpp::github_rest::RepositoryContent execute(simple_cpp::github_rest::Client &client);
};
}

#endif // SIMPLE_CPP_GITHUB_REST_GET_REPOSITORY_CONTENT_HPP
