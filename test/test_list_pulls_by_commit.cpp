#include <catch2/catch_test_macros.hpp>
#include <simple_cpp_github_rest/list_pulls_by_commit.hpp>

#include "mock_client.hpp"

TEST_CASE("list_pulls_by_commit")
{
  MockClient client;
  client.enqueue_resource_response("sample_list_pulls_by_commit");

  simple_cpp::github_rest::ListPullsByCommitRequest request{ "commitSha" };

  const auto pulls = request.execute(client);

  REQUIRE(pulls
          == std::vector<simple_cpp::github_rest::Pull>{ { 1347,
            "Please pull these awesome changes in!",
            { "6dcb09b5b57875f334f61aebed695e2e4193db5e" },
            { "7dcb09b5b57875f334f61aebed695e2e4193db5e" } } });
  REQUIRE(client.pop_recorded_request() == RecordedRequest{ "GET", "/commits/commitSha/pulls?per_page=30&page=1", "" });
}