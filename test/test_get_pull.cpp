#include <catch2/catch_test_macros.hpp>
#include <simple_cpp_github_rest/get_pull.hpp>

#include "mock_client.hpp"

TEST_CASE("get_pull")
{
  MockClient client;
  client.enqueue_resource_response("sample_pull");

  simple_cpp::github_rest::GetPullRequest request{ 33 };

  const auto pull = request.execute(client);

  REQUIRE(pull.number == 1347);
  REQUIRE(pull.head.sha == "6dcb09b5b57875f334f61aebed695e2e4193db5e");
  REQUIRE(pull.base.sha == "7dcb09b5b57875f334f61aebed695e2e4193db5e");
  REQUIRE(pull.body == "Please pull these awesome changes in!");
  REQUIRE(client.pop_recorded_request() == RecordedRequest{ "GET", "/pulls/33", "" });
}