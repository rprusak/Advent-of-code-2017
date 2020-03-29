#include "common.h"

#include <fstream>
#include <iostream>

namespace common {
std::vector<std::string> readInput(const std::string& filename) {
  std::vector<std::string> result;

  std::ifstream input{filename};
  if (!input.is_open()) {
    std::cerr << "could not open file " << filename << std::endl;
    return result;
  }

  std::string line;
  while (std::getline(input, line)) result.push_back(line);

  return result;
}
}  // namespace common
