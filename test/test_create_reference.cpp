#include <catch2/catch_test_macros.hpp>
#include <simple_cpp_github_rest/create_reference.hpp>

#include "mock_client.hpp"

TEST_CASE("create_reference")
{
  MockClient client;
  client.enqueue_resource_response(201, "sample_reference");

  const simple_cpp::github_rest::CreateReferenceRequestBody requestBody{ .ref = "branch/develop", .sha = "commitSha" };
  simple_cpp::github_rest::CreateReferenceRequest request{ requestBody };

  const auto reference = request.execute(client);

  REQUIRE(reference.object.sha == "aa218f56b14c9653891f9e74264a383fa43fefbd");
  REQUIRE(reference.object.type == "commit");
  REQUIRE(client.pop_recorded_request()
          == RecordedRequest{ "POST", "/git/refs", "{\"ref\":\"branch/develop\",\"sha\":\"commitSha\"}" });
}