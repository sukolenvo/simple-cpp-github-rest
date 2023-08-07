#ifndef SIMPLE_CPP_GITHUB_REST_CREATE_COMMIT_HPP
#define SIMPLE_CPP_GITHUB_REST_CREATE_COMMIT_HPP

#include <string>

#include <glaze/glaze.hpp>

#include "client.hpp"
#include "dto/commit.hpp"
#include "request.hpp"

namespace simple_cpp::github_rest {

struct Author
{
  std::string name;
  std::string email;
};

struct CreateCommitRequestBody
{
  std::string message;
  Author author;
  std::string tree;
};

class CreateCommitRequest
{
  simple_cpp::github_rest::Request request;
  CreateCommitRequestBody requestBody;

public:
  explicit CreateCommitRequest(CreateCommitRequestBody body);

  simple_cpp::github_rest::Commit execute(simple_cpp::github_rest::Client &client);
};

} // namespace simple_cpp::github_rest

template<> struct glz::meta<simple_cpp::github_rest::Author>
{
  using T = simple_cpp::github_rest::Author;
  static constexpr auto value =
    object("name", &simple_cpp::github_rest::Author::name, "email", &simple_cpp::github_rest::Author::email);
};

template<> struct glz::meta<simple_cpp::github_rest::CreateCommitRequestBody>
{
  using T = simple_cpp::github_rest::CreateCommitRequestBody;
  static constexpr auto value = object("message",
    &simple_cpp::github_rest::CreateCommitRequestBody::message,
    "author",
    &simple_cpp::github_rest::CreateCommitRequestBody::author,
    "tree",
    &simple_cpp::github_rest::CreateCommitRequestBody::tree);
};

#endif // SIMPLE_CPP_GITHUB_REST_CREATE_COMMIT_HPP
