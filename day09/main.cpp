#include <iostream>

#include "common.h"
#include "day09.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "invalid input" << std::endl;
  }

  auto input = common::readInput(argv[1]);

  std::cout << "Part1: " << getGroupsCount(input.front()) << std::endl;
  std::cout << "Part2: " << getCancelledCharsCount(input.front()) << std::endl;

  return 0;
}