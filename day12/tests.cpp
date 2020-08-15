#include <argp.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "day12.h"

TEST(day12_test, test_parseString) {
  auto program = day12::parseString("4 <-> 2, 3, 6");

  ASSERT_EQ(program._programId, 4u);
  ASSERT_EQ(program._connectedProgramsId.size(), 3u);
  ASSERT_EQ(program._connectedProgramsId[0], 2u);
  ASSERT_EQ(program._connectedProgramsId[1], 3u);
  ASSERT_EQ(program._connectedProgramsId[2], 6u);
}

TEST(day12_test, test_partOne) {
  std::vector<std::string> input{"0 <-> 2",       "1 <-> 1", "2 <-> 0, 3, 4", "3 <-> 2, 4",
                                 "4 <-> 2, 3, 6", "5 <-> 6", "6 <-> 4, 5"};

  ASSERT_EQ(day12::partOne(input), 6u);
}

TEST(day12_test, test_partTwo) {
  std::vector<std::string> input{"0 <-> 2",       "1 <-> 1", "2 <-> 0, 3, 4", "3 <-> 2, 4",
                                 "4 <-> 2, 3, 6", "5 <-> 6", "6 <-> 4, 5"};

  ASSERT_EQ(day12::partTwo(input), 2u);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}