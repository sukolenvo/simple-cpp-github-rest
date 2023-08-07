#include <catch2/catch_test_macros.hpp>
#include <simple_cpp_github_rest/get_reference.hpp>

#include "mock_client.hpp"

TEST_CASE("get_reference")
{
  MockClient client;
  client.enqueue_resource_response("sample_reference");

  simple_cpp::github_rest::GetReferenceRequest request{ "branch/main" };

  const auto reference = request.execute(client);

  REQUIRE(reference.object.sha == "aa218f56b14c9653891f9e74264a383fa43fefbd");
  REQUIRE(reference.object.type == "commit");
  REQUIRE(client.pop_recorded_request()
          == RecordedRequest{ "GET",
            "/git/ref/branch/main",
            "" });
}