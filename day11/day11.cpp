#include "day11.h"

#include <algorithm>
#include <tuple>

#include "common.h"

namespace day11 {

struct Hex {
  int _x;
  int _y;
  int _z;

  Hex getNext(const std::string &direction) const {
    if (direction == "n")
      return Hex{_x, _y + 1, _z - 1};
    else if (direction == "ne")
      return Hex{_x + 1, _y, _z - 1};
    else if (direction == "se")
      return Hex{_x + 1, _y - 1, _z};
    else if (direction == "s")
      return Hex{_x, _y - 1, _z + 1};
    else if (direction == "sw")
      return Hex{_x - 1, _y, _z + 1};
    else if (direction == "nw")
      return Hex{_x - 1, _y + 1, _z};
    else
      throw std::runtime_error{"Invalid direction: " + direction};
  }

};


unsigned partOne(const std::string &input) {
  auto directions = common::split(input, ",");

  Hex currentHex{0, 0, 0};
  for (const auto &direction : directions) {
    currentHex = currentHex.getNext(direction);
  }

  return unsigned(std::max({currentHex._x, currentHex._y, currentHex._z}));
}

unsigned partTwo(const std::string &input) {
  auto directions = common::split(input, ",");

  unsigned furtherDistance{0};

  Hex currentHex{0, 0, 0};
  for (const auto &direction : directions) {
    currentHex = currentHex.getNext(direction);
    unsigned distance = unsigned(std::max({currentHex._x, currentHex._y, currentHex._z}));
    if (distance > furtherDistance)
      furtherDistance = distance;
  }

  return furtherDistance;
}
}  // namespace day11