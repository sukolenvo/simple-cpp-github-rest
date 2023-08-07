#include <catch2/catch_test_macros.hpp>
#include <simple_cpp_github_rest/create_tree.hpp>

#include "mock_client.hpp"

TEST_CASE("create_tree")
{
  MockClient client;
  client.enqueue_resource_response(201, "sample_tree");

  const simple_cpp::github_rest::CreateTreeRequestBody requestBody{
    .tree = { { .path = "filePath", .mode = simple_cpp::github_rest::MODE_FILE, .content = "file body" } },
    .base_tree = { "baseTreSha" }
  };
  simple_cpp::github_rest::CreateTreeRequest request{ requestBody };

  const auto tree = request.execute(client);

  REQUIRE(tree.sha == "cd8274d15fa3ae2ab983129fb037999f264ba9a7");
  REQUIRE(client.pop_recorded_request()
          == RecordedRequest{ "POST",
            "/git/trees",
            "{\"tree\":[{\"path\":\"filePath\",\"mode\":\"100644\",\"content\":\"file body\"}],"
            "\"base_tree\":\"baseTreSha\"}" });
}

TEST_CASE("create_tree_no_base")
{
  MockClient client;
  client.enqueue_resource_response(201, "sample_tree");

  const simple_cpp::github_rest::CreateTreeRequestBody requestBody{
    .tree = { { .path = "filePath", .mode = simple_cpp::github_rest::MODE_FILE, .content = "file body" } },
    .base_tree = {}
  };
  simple_cpp::github_rest::CreateTreeRequest request{ requestBody };

  const auto tree = request.execute(client);

  REQUIRE(tree.sha == "cd8274d15fa3ae2ab983129fb037999f264ba9a7");
  REQUIRE(
    client.pop_recorded_request()
    == RecordedRequest{
      "POST", "/git/trees", "{\"tree\":[{\"path\":\"filePath\",\"mode\":\"100644\",\"content\":\"file body\"}]}" });
}