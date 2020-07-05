#include <iostream>

#include "common.h"
#include "day08.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "invalid input" << std::endl;
  }

  auto input = common::readInput(argv[1]);
  auto commands = parseInput(input);

  {
    Registers registers;
    executeCommands(commands, registers);
    std::cout << "Part 1: " << getMaximalRegisterValue(registers) << std::endl;
  }

  {
    Registers registers;
    std::cout << "Part 2: " << executeCommands(commands, registers) << std::endl;
  }

  return 0;
}
