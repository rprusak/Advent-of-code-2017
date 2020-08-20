#include <gtest/gtest.h>

#include "day13.h"

TEST(day13_test, test_parseLayers) {
  std::vector<std::string> input{"0: 1", "1: 5", "3: 3"};
  auto layers = day13::parseLayers(input);
  ASSERT_EQ(layers.size(), 3u);
  ASSERT_EQ(layers[0].getId(), 0u);
  ASSERT_EQ(layers[0].getDepth(), 1u);
  ASSERT_EQ(layers[1].getId(), 1u);
  ASSERT_EQ(layers[1].getDepth(), 5u);
  ASSERT_EQ(layers[2].getId(), 3u);
  ASSERT_EQ(layers[2].getDepth(), 3u);
}

TEST(day13_test, test_partOne) {
  std::vector<std::string> input{"0: 3", "1: 2", "4: 4", "6: 4"};
  ASSERT_EQ(day13::partOne(input), 24u);
}

TEST(day13_test, test_canPassWithDelay) {
  std::vector<std::string> input{"0: 3", "1: 2", "4: 4", "6: 4"};
  auto layers = day13::parseLayers(input);
  ASSERT_TRUE(day13::canPassWithDelay(layers, 10));
}

TEST(day13_test, test_partTwo) {
  std::vector<std::string> input{"0: 3", "1: 2", "4: 4", "6: 4"};
  ASSERT_EQ(day13::partTwo(input), 10u);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}