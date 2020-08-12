#include <gtest/gtest.h>

#include "day11.h"

TEST(day11, test_partOne) {
  ASSERT_EQ(day11::partOne("ne,ne,sw,sw"), 0u);
  ASSERT_EQ(day11::partOne("ne,ne,ne"), 3u);
  ASSERT_EQ(day11::partOne("ne,ne,s,s"), 2u);
  ASSERT_EQ(day11::partOne("se,sw,se,sw,sw"), 3u);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}