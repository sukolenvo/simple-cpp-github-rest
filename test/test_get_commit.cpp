#include <catch2/catch_test_macros.hpp>
#include <simple_cpp_github_rest/get_commit.hpp>

#include "mock_client.hpp"

TEST_CASE("get_commit")
{
  MockClient client;
  client.enqueue_resource_response("sample_commit");

  simple_cpp::github_rest::GetCommitRequest request{ "commitSha" };

  const auto commit = request.execute(client);

  REQUIRE(commit.sha == "7638417db6d59f3c431d3e1f261cc637155684cd");
  REQUIRE(commit.tree.sha == "827efc6d56897b048c772eb4087f854f46256132");
  REQUIRE(client.pop_recorded_request() == RecordedRequest{ "GET", "/git/commits/commitSha", "" });
}