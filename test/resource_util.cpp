#include <array>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "resourse_util.hpp"

auto readFile(auto path)
{
  std::ifstream stream(path);
  if (stream.is_open()) {
    std::stringstream buffer;
    buffer << stream.rdbuf();
    stream.close();
    return buffer.str();
  } else {
    throw std::runtime_error("Failed to open task input file");
  }
}

std::string readTestJson(const char *json)
{
  std::array<char, 100> filename{};
  filename.fill(0);
  auto status = std::snprintf(filename.data(), filename.max_size(), "resources/%s.json", json);
  if (status < 0 || static_cast<size_t>(status) >= filename.max_size()) {
    throw std::runtime_error("Failed to construct task input filename");
  }
  return readFile(filename.data());
}
