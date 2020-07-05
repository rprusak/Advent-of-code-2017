#ifndef DAY09_DAY09_H
#define DAY09_DAY09_H

#include <memory>
#include <string>
#include <vector>

struct Group {
  std::vector<std::shared_ptr<Group>> _childGroups;
};

unsigned getGroupsCount(const std::string& line);
unsigned getCancelledCharsCount(const std::string& line);
unsigned calculateGroups(const Group& group, unsigned level = 1);

#endif  // DAY09_DAY09_H
