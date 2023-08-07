#include <catch2/catch_test_macros.hpp>
#include <simple_cpp_github_rest/create_commit.hpp>

#include "mock_client.hpp"

TEST_CASE("create_commit")
{
  MockClient client;
  client.enqueue_resource_response(201, "sample_commit");

  const simple_cpp::github_rest::CreateCommitRequestBody requestBody{
    .message = "commitMessage", .author = { .name = "authorName", .email = "authorEmail" }, .tree = "treeSha"
  };
  simple_cpp::github_rest::CreateCommitRequest request{ requestBody };

  const auto commit = request.execute(client);

  REQUIRE(commit.sha == "7638417db6d59f3c431d3e1f261cc637155684cd");
  REQUIRE(commit.tree.sha == "827efc6d56897b048c772eb4087f854f46256132");
  REQUIRE(client.pop_recorded_request()
          == RecordedRequest{ "POST",
            "/git/commits",
            "{\"message\":\"commitMessage\","
            "\"author\":{\"name\":\"authorName\",\"email\":\"authorEmail\"},"
            "\"tree\":\"treeSha\"}" });
}