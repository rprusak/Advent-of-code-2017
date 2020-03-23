#include <iostream>

#include "common.h"

unsigned long getSum(const std::string& input) {
  unsigned long result{0};

  for (std::string::size_type index = 0; index < input.size(); index++) {
    auto nextIndex = (index + 1) % input.size();

    if (input[index] == input[nextIndex]) {
      result += input[index] - 48;
    }
  }

  return result;
}

unsigned long getSumByOffset(const std::string& input) {
  unsigned long result{0};
  std::string::size_type offset{input.size() / 2};

  for (std::string::size_type index = 0; index < input.size(); index++) {
    auto nextIndex = (index + offset) % input.size();

    if (input[index] == input[nextIndex]) {
      result += input[index] - 48;
    }
  }

  return result;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "invalid arguments" << std::endl;
    exit(EXIT_FAILURE);
  }

  auto input = readInput(argv[1]);
  std::cout << getSum(input[0]) << std::endl;
  std::cout << getSumByOffset(input[0]) << std::endl;

  return 0;
}
