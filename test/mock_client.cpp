#include <iostream>
#include <stdexcept>
#include <string>

#include "mock_client.hpp"
#include "resourse_util.hpp"

std::ostream& operator <<(std::ostream& os, const RecordedRequest& value)
{
  os << "RecordedRequest(" << value.method << ' ' << value.path << ", " << value.body << ')';
  return os;
}

MockClient::MockClient() : simple_cpp::github_rest::Client("", "", "")
{}

MockClient::~MockClient()
{
  if (!mock_responses.empty()) {
    std::cerr << std::to_string(mock_responses.size()) << " unused mocked responses";
  }
}

simple_cpp::github_rest::Response MockClient::get(const std::string &url)
{
  recorded_requests.emplace("GET", url, "");
  if (mock_responses.empty()) {
    throw std::runtime_error(std::string("no response enqueued for: ") + url);
  }
  const auto response = mock_responses.front();
  mock_responses.pop();
  return response;
}

simple_cpp::github_rest::Response MockClient::post(const std::string &url, const std::string &body)
{
  recorded_requests.emplace("POST", url, body);
  if (mock_responses.empty()) {
    throw std::runtime_error(std::string("no response enqueued for: ") + url);
  }
  const auto response = mock_responses.front();
  mock_responses.pop();
  return response;
}
simple_cpp::github_rest::Response MockClient::patch(const std::string &url, const std::string &body)
{
  recorded_requests.emplace("PATCH", url, body);
  if (mock_responses.empty()) {
    throw std::runtime_error(std::string("no response enqueued for: ") + url);
  }
  const auto response = mock_responses.front();
  mock_responses.pop();
  return response;
}

void MockClient::enqueue_response(long code, std::string body)
{
  mock_responses.emplace(code, std::move(body));
}

void MockClient::enqueue_response(std::string body)
{
  this->enqueue_response(200, std::move(body));
}

void MockClient::enqueue_resource_response(const std::string &resourceName)
{
  this->enqueue_response(readTestJson(resourceName.c_str()));
}

void MockClient::enqueue_resource_response(long code, const std::string &resourceName)
{
  this->enqueue_response(code, readTestJson(resourceName.c_str()));
}

RecordedRequest MockClient::pop_recorded_request()
{
  if (recorded_requests.empty()) {
    throw std::runtime_error("no recorded request");
  }
  const RecordedRequest request = recorded_requests.front();
  recorded_requests.pop();
  return request;
}