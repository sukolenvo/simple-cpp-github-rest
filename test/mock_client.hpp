#ifndef SIMPLE_CPP_GITHUB_REST_MOCK_CLIENT_HPP
#define SIMPLE_CPP_GITHUB_REST_MOCK_CLIENT_HPP

#include <compare>
#include <ostream>
#include <queue>

#include <simple_cpp_github_rest/client.hpp>

struct RecordedRequest
{
  std::string method;
  std::string path;
  std::string body;
  std::strong_ordering operator<=>(const RecordedRequest &other) const = default;
};

std::ostream &operator<<(std::ostream &os, const RecordedRequest &value);

class MockClient : public simple_cpp::github_rest::Client
{
  std::queue<RecordedRequest> recorded_requests;
  std::queue<simple_cpp::github_rest::Response> mock_responses;

public:
  MockClient();
  ~MockClient();

  void enqueue_response(std::string body);

  void enqueue_response(long code, std::string body);

  void enqueue_resource_response(const std::string &resourceName);

  void enqueue_resource_response(long code, const std::string &resourceName);

  RecordedRequest pop_recorded_request();

  simple_cpp::github_rest::Response get(const std::string &url) override;

  simple_cpp::github_rest::Response post(const std::string &url, const std::string &body) override;

  simple_cpp::github_rest::Response patch(const std::string &url, const std::string &body) override;
};

#endif // SIMPLE_CPP_GITHUB_REST_MOCK_CLIENT_HPP
