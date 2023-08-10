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
  REQUIRE(pull.body == std::optional{ "Please pull these awesome changes in!" });
  REQUIRE(client.pop_recorded_request() == RecordedRequest{ "GET", "/pulls/33", "" });
}

TEST_CASE("get_pull_empty_body")
{
  MockClient client;
  client.enqueue_resource_response("sample_pull_empty_body");

  simple_cpp::github_rest::GetPullRequest request{ 33 };

  const auto pull = request.execute(client);

  REQUIRE(pull.number == 2);
  REQUIRE(pull.head.sha == "5476ffb41ee8ebf6dc1a4981d541d2e84c6a39a3");
  REQUIRE(pull.base.sha == "f098e94fe6bddf83a98b9d3fbf53b2a015731ceb");
  REQUIRE(pull.body == std::optional<std::string>{});
  REQUIRE(client.pop_recorded_request() == RecordedRequest{ "GET", "/pulls/33", "" });
}