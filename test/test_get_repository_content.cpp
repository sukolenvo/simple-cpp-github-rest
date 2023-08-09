#include <catch2/catch_test_macros.hpp>
#include <simple_cpp_github_rest/get_repository_content.hpp>

#include "mock_client.hpp"

TEST_CASE("get_repository_content")
{
  MockClient client;
  client.enqueue_resource_response("sample_repository_content");

  simple_cpp::github_rest::GetRepositoryContentRequest request{ "README.md", "branch/main" };

  const auto content = request.execute(client);

  REQUIRE(content.type == "file");
  REQUIRE(content.encoding == "base64");
  REQUIRE(content.content == "aW5zdHJ1Y3Rpb246IDAuODUKbGluZTogMC44NgpjbGFzczogMC45NApicmFu\nY2g6IDAuNjcKbWV0aG9kOiAwLjg0CmNvbXBsZXhpdHk6IDAuNzAK\n");
  REQUIRE(content.parse_content() == R"(instruction: 0.85
line: 0.86
class: 0.94
branch: 0.67
method: 0.84
complexity: 0.70
)");
  REQUIRE(client.pop_recorded_request() == RecordedRequest{ "GET", "/contents/README.md?ref=branch/main", "" });
}