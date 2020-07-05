#include "day09.h"

#include <stack>
#include <utility>

namespace {
std::pair<std::shared_ptr<Group>, unsigned> processBuffer(const std::string& buffer) {
  std::stack<std::shared_ptr<Group>> stack;
  std::shared_ptr<Group> head{nullptr};
  unsigned canceledCount{0};

  bool isInGarbage{false};
  bool shouldIgnoreChar{false};

  for (char c : buffer) {
    if (isInGarbage and shouldIgnoreChar) {
      shouldIgnoreChar = false;
      continue;
    }

    if (isInGarbage and c == '>') {
      isInGarbage = false;
      continue;
    }

    if (isInGarbage and c == '!') {
      shouldIgnoreChar = true;
      continue;
    }

    if (isInGarbage) {
      canceledCount++;
      continue;
    }

    if (c == '<') {
      isInGarbage = true;
      continue;
    }

    if (c == '{') {
      auto newGroup = std::make_shared<Group>();

      if (head == nullptr) head = newGroup;

      if (!stack.empty()) {
        stack.top()->_childGroups.push_back(newGroup);
      }

      stack.push(newGroup);
    }

    if (c == '}') {
      stack.pop();
    }
  }

  return std::make_pair(head, canceledCount);
}
}  // namespace

unsigned getGroupsCount(const std::string& str) {
  auto res = processBuffer(str);
  return calculateGroups(*res.first);
}

unsigned calculateGroups(const Group& group, unsigned level) {
  unsigned result{0};
  result += level;
  for (const auto& child : group._childGroups) result += calculateGroups(*child, level + 1);

  return result;
}

unsigned getCancelledCharsCount(const std::string& line) {
  auto res = processBuffer(line);
  return res.second;
}