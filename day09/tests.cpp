#include <gtest/gtest.h>

#include "day09.h"

TEST(getGroupsCount, test) {
  ASSERT_EQ(getGroupsCount("{}"), 1u);
  ASSERT_EQ(getGroupsCount("{{{}}}"), 6u);
  ASSERT_EQ(getGroupsCount("{{},{}}"), 5u);
  ASSERT_EQ(getGroupsCount("{{{},{},{{}}}}"), 16u);
  ASSERT_EQ(getGroupsCount("{<{},{},{{}}>}"), 1u);
  ASSERT_EQ(getGroupsCount("{<a>,<a>,<a>,<a>}"), 1u);
  ASSERT_EQ(getGroupsCount("{{<ab>},{<ab>},{<ab>},{<ab>}}"), 9u);
  ASSERT_EQ(getGroupsCount("{{<!!>},{<!!>},{<!!>},{<!!>}}"), 9u);
  ASSERT_EQ(getGroupsCount("{{<a!>},{<a!>},{<a!>},{<ab>}}"), 3u);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}