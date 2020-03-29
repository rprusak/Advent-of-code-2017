#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

#include "common.h"

unsigned getChecksum(const std::vector<std::vector<unsigned>>& spreadsheet) {
  unsigned checksum{0};

  for (const auto& row : spreadsheet) {
    auto min = *std::min_element(row.begin(), row.end());
    auto max = *std::max_element(row.begin(), row.end());
    checksum += max - min;
  }

  return checksum;
}

std::vector<std::vector<unsigned>> createSpreadsheet(const std::vector<std::string>& input) {
  std::vector<std::vector<unsigned>> spreadsheet;

  for (const auto& line : input) {
    std::stringstream lineStream{line};
    std::vector<unsigned> lineValues;
    unsigned value{0};

    while (lineStream) {
      lineStream >> value;
      lineValues.push_back(value);
    }

    spreadsheet.push_back(lineValues);
  }

  return spreadsheet;
}

std::optional<unsigned> getValueFromRow(const std::vector<unsigned>& row) {
  for (size_t index = 0; index < row.size(); index++) {
    for (size_t nextIndex = index + 1; nextIndex < row.size(); nextIndex++) {
      auto biggerValue = std::max(row[index], row[nextIndex]);
      auto smallerValue = std::min(row[index], row[nextIndex]);

      if (biggerValue % smallerValue == 0) {
        return std::make_optional(biggerValue / smallerValue);
      }
    }
  }

  return std::nullopt;
}

unsigned getChecksumFromDivisibleValues(const std::vector<std::vector<unsigned>>& spreadsheet) {
  unsigned checksum{0};

  for (const auto& row : spreadsheet) {
    auto value = getValueFromRow(row);
    if (value) checksum += value.value();
  }

  return checksum;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Invalid arguments" << std::endl;
    exit(EXIT_FAILURE);
  }

  auto input = common::readInput(argv[1]);
  auto spreadsheet = createSpreadsheet(input);
  auto checksum = getChecksum(spreadsheet);
  std::cout << checksum << std::endl;

  auto secondChecksum = getChecksumFromDivisibleValues(spreadsheet);
  std::cout << secondChecksum << std::endl;

  return 0;
}
