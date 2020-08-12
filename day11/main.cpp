#include <iostream>
#include <limits>
#include <set>
#include <string>

#include "common.h"
#include "day11.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Invalid input" << std::endl;
    return 1;
  }

  auto input = common::readInput(argv[1]);
  std::cout << "PART1: " << day11::partOne(input[0]) << std::endl;
  std::cout << "PART2: " << day11::partTwo(input[0]) << std::endl;

  return 0;
}
