#include <algorithm>
#include <stdexcept>

#include <decoder.hpp>

#include "repository_content.hpp"

std::string simple_cpp::github_rest::RepositoryContent::parse_content() const
{
  if (encoding != "base64") {
    throw std::runtime_error("Unsupported encoding");
  }
  std::string filtered = content;
  filtered.erase(std::remove(filtered.begin(), filtered.end(), '\n'), filtered.cend());
  return simple_cpp::base64::decode(filtered);
}
