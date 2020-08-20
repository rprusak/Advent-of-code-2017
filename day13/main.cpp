#include <iostream>

#include "common.h"
#include "day13.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Invalid input" << std::endl;
    return 1;
  }

  auto input = common::readInput(argv[1]);
  std::cout << "part one: " << day13::partOne(input) << std::endl;
  std::cout << "part two: " << day13::partTwo(input) << std::endl;

  return 0;
}
