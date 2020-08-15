#include "day12.h"

#include <map>
#include <queue>
#include <regex>
#include <set>

#include "common.h"

namespace day12 {
Program parseString(const std::string& str) {
  static std::regex pattern{R"#(^(\d+)\s+<->\s+((.+))$)#"};
  std::smatch matchResult;

  if (!std::regex_match(str, matchResult, pattern))
    throw std::runtime_error{"Could not parse string: " + str};

  Program program;
  program._programId = std::stoul(matchResult[1].str());

  auto programsId = common::split(matchResult[2].str(), ",");
  for (const auto& id : programsId) program._connectedProgramsId.push_back(std::stoul(id));

  return program;
}

std::vector<Program> parseInput(const std::vector<std::string>& input) {
  std::vector<Program> programs;
  programs.reserve(input.size());

  for (const auto& str : input) programs.push_back(parseString(str));

  return programs;
}

std::map<unsigned, std::vector<unsigned>> createProgramsMap(const std::vector<Program>& programs) {
  std::map<unsigned, std::vector<unsigned>> map;

  for (const auto& program : programs) map[program._programId] = program._connectedProgramsId;

  return map;
}

unsigned partOne(const std::vector<std::string>& input) {
  auto inputPrograms = parseInput(input);
  auto programsMap = createProgramsMap(inputPrograms);

  std::set<unsigned> visitedPrograms;
  std::queue<unsigned> programsToCheck;

  programsToCheck.push(0);
  visitedPrograms.insert(0);

  while (!programsToCheck.empty()) {
    auto programId = programsToCheck.front();
    programsToCheck.pop();
    visitedPrograms.insert(programId);

    const auto& connectedPrograms = programsMap[programId];
    for (const auto& connectedProgram : connectedPrograms)
      if (visitedPrograms.count(connectedProgram) == 0) programsToCheck.push(connectedProgram);
  }

  return visitedPrograms.size();
}

unsigned partTwo(const std::vector<std::string>& input) {
  auto inputPrograms = parseInput(input);
  auto programsMap = createProgramsMap(inputPrograms);

  std::set<unsigned> visitedPrograms;
  std::set<unsigned> programsWithoutGroup;
  std::queue<unsigned> programsToCheck;
  unsigned foundGroups{0};

  for (const auto& [program, connectedPrograms] : programsMap) programsWithoutGroup.insert(program);

  while (!programsWithoutGroup.empty()) {
    foundGroups++;
    auto startProgram = *programsWithoutGroup.begin();
    programsToCheck.push(startProgram);
    visitedPrograms.insert(startProgram);
    programsWithoutGroup.erase(startProgram);

    while (!programsToCheck.empty()) {
      auto programId = programsToCheck.front();
      programsToCheck.pop();
      visitedPrograms.insert(programId);
      programsWithoutGroup.erase(programId);

      const auto& connectedPrograms = programsMap[programId];
      for (const auto& connectedProgram : connectedPrograms)
        if (visitedPrograms.count(connectedProgram) == 0) programsToCheck.push(connectedProgram);
    }
  }

  return foundGroups;
}
}  // namespace day12
