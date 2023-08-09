#include <string>
#include <utility>

#include <curl/curl.h>
#include <glaze/glaze.hpp>

#include "client.hpp"
#include "exception.hpp"

namespace simple_cpp::github_rest {

static size_t stringWriteCallback(char *contents, size_t size, size_t nmemb, std::string *writerData)
{
  if (writerData == nullptr) {
    return 0;
  }
  writerData->append(contents, size * nmemb);
  return size * nmemb;
}

Client::Client(std::string owner_, std::string repo_name_, std::string token_)
  : owner(std::move(owner_)), repo_name(std::move(repo_name_)), token(std::move(token_))
{}

simple_cpp::github_rest::Response Client::get(const std::string &path)
{
  CURL *curl;
  CURLcode res;
  std::string responseBody;

  curl = curl_easy_init();
  if (curl) {
    std::string url{ "https://api.github.com/repos/" };
    url += owner + "/" + repo_name + path;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    struct curl_slist *headerList = nullptr;
    headerList = curl_slist_append(headerList, "X-GitHub-Api-Version: 2022-11-28");
    std::string token_header = std::string("Authorization: Bearer ") + token;
    if (!token.empty()) {
      headerList = curl_slist_append(headerList, token_header.c_str());
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Coverage Notes App");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, stringWriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBody);
    res = curl_easy_perform(curl);
    if (res == CURLE_OK) {
      long statusCode{};
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &statusCode);
      curl_easy_cleanup(curl);
      return { statusCode, responseBody };
    } else {
    }
  }
  throw simple_cpp::github_rest::GithubRestException("curl init failed");
}

simple_cpp::github_rest::Response
  Client::request_with_body(const std::string &method, const std::string &path, const std::string &body)
{
  CURL *curl;
  CURLcode res;
  std::string responseBody;

  curl = curl_easy_init();
  if (curl) {
    std::string url{ "https://api.github.com/repos/" };
    url += owner + "/" + repo_name + path;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    struct curl_slist *headerList = nullptr;
    headerList = curl_slist_append(headerList, "X-GitHub-Api-Version: 2022-11-28");
    headerList = curl_slist_append(headerList, "Content-type: application/json");
    std::string token_header = std::string("Authorization: Bearer ") + token;
    if (!token.empty()) {
      headerList = curl_slist_append(headerList, token_header.c_str());
    }
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Coverage Notes App");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, stringWriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBody);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.size());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
    res = curl_easy_perform(curl);
    if (res == CURLE_OK) {
      long statusCode{};
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &statusCode);
      curl_easy_cleanup(curl);
      return { statusCode, responseBody };
    } else {
    }
  }
  throw simple_cpp::github_rest::GithubRestException("curl init failed");
}

simple_cpp::github_rest::Response Client::post(const std::string &path, const std::string &body)
{
  return request_with_body("POST", path, body);
}

simple_cpp::github_rest::Response Client::patch(const std::string &path, const std::string &body)
{
  return request_with_body("PATCH", path, body);
}

} // namespace simple_cpp::github_rest
