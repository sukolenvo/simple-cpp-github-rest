#include <catch2/catch_test_macros.hpp>
#include <simple_cpp_github_rest/update_pull.hpp>

#include "mock_client.hpp"

TEST_CASE("update_pull")
{
  MockClient client;
  client.enqueue_resource_response("sample_pull");

  const simple_cpp::github_rest::UpdatePullRequestBody requestBody{ .body = "new body" };
  simple_cpp::github_rest::UpdatePullRequest request{ 1, requestBody };

  const auto reference = request.execute(client);

  REQUIRE(reference.body == "Please pull these awesome changes in!");
  REQUIRE(client.pop_recorded_request() == RecordedRequest{ "PATCH", "/pulls/1", "{\"body\":\"new body\"}" });
}