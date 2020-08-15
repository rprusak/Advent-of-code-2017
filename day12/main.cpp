#include <iostream>

#include "common.h"
#include "day12.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Invalid input!" << std::endl;
    return 1;
  }

  auto input = common::readInput(argv[1]);
  std::cout << "part one: " << day12::partOne(input) << std::endl;
  std::cout << "part two: " << day12::partTwo(input) << std::endl;

  return 0;
}
