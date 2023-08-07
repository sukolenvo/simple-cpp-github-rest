#ifndef SIMPLE_CPP_GITHUB_REST_CREATE_TREE_HPP
#define SIMPLE_CPP_GITHUB_REST_CREATE_TREE_HPP

#include <vector>

#include <glaze/glaze.hpp>

#include "client.hpp"
#include "dto/tree.hpp"
#include "request.hpp"

namespace simple_cpp::github_rest {

static const std::string MODE_FILE{ "100644" };

struct CreateTreeEntry
{
  std::string path;
  std::string mode;
  std::string content;
};

struct CreateTreeRequestBody
{
  std::vector<CreateTreeEntry> tree;
  std::optional<std::string> base_tree;
};

class CreateTreeRequest
{
  simple_cpp::github_rest::Request request;
  CreateTreeRequestBody requestBody;

public:
  explicit CreateTreeRequest(CreateTreeRequestBody body);

  simple_cpp::github_rest::Tree execute(simple_cpp::github_rest::Client &client);
};

} // namespace simple_cpp::github_rest

template<> struct glz::meta<simple_cpp::github_rest::CreateTreeEntry>
{
  using T = simple_cpp::github_rest::CreateTreeEntry;
  static constexpr auto value = object("path",
    &simple_cpp::github_rest::CreateTreeEntry::path,
    "mode",
    &simple_cpp::github_rest::CreateTreeEntry::mode,
    "content",
    &simple_cpp::github_rest::CreateTreeEntry::content);
};

template<> struct glz::meta<simple_cpp::github_rest::CreateTreeRequestBody>
{
  using T = simple_cpp::github_rest::CreateTreeRequestBody;
  static constexpr auto value = object("tree",
    &simple_cpp::github_rest::CreateTreeRequestBody::tree,
    "base_tree",
    &simple_cpp::github_rest::CreateTreeRequestBody::base_tree);
};

#endif // SIMPLE_CPP_GITHUB_REST_CREATE_TREE_HPP
