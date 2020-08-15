#ifndef DAY12_DAY12_H
#define DAY12_DAY12_H

#include <string>
#include <vector>

namespace day12 {
struct Program {
  unsigned _programId;
  std::vector<unsigned> _connectedProgramsId;
};

Program parseString(const std::string& str);
unsigned partOne(const std::vector<std::string>& input);
unsigned partTwo(const std::vector<std::string>& input);
}  // namespace day12

#endif  // DAY12_DAY12_H