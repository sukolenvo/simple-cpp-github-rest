#include <catch2/catch_test_macros.hpp>
#include <simple_cpp_github_rest/get_pull.hpp>

#include "mock_client.hpp"

TEST_CASE("get_pull")
{
  MockClient client;
  client.enqueue_resource_response("sample_pull");

  simple_cpp::github_rest::GetPullRequest request{33};

  const auto pull = request.execute(client);

  REQUIRE(pull.number == 1347);
  REQUIRE(client.pop_recorded_request() == RecordedRequest{ "GET", "/pulls/33", "" });
}