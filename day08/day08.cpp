#include "day08.h"

#include <limits>
#include <regex>

Condition::Type getConditionType(const std::string& type) {
  if (type == ">")
    return Condition::Type::GREATER;
  else if (type == ">=")
    return Condition::Type::GREATER_OR_EQUAL;
  else if (type == "==")
    return Condition::Type::EQUAL;
  else if (type == "<=")
    return Condition::Type::LESS_OR_EQUAL;
  else if (type == "<")
    return Condition::Type::LESS;
  else
    return Condition::Type::NOT_EQUAL;
}

Command parseCommand(const std::string& str) {
  static std::regex pattern{
    R"#(^(\w+)\s+(dec|inc)\s+(-?\d+)\s+if\s+(\w+)\s+(>|>=|==|<=|<|<=|!=)\s+(-?\d+)$)#"};

  std::smatch matchResults;
  if (!std::regex_match(str, matchResults, pattern))
    throw std::runtime_error("could not match line " + str);

  Command command;

  command._instruction._registerName = matchResults[1].str();
  command._instruction._type =
    matchResults[2].str() == "inc" ? Instruction::Type::INC : Instruction::Type::DEC;
  command._instruction._value = std::stoi(matchResults[3].str());

  command._condition._registerName = matchResults[4].str();
  command._condition._type = getConditionType(matchResults[5].str());
  command._condition._value = std::stoi(matchResults[6].str());

  return command;
}

std::vector<Command> parseInput(const std::vector<std::string>& input) {
  std::vector<Command> commands;

  for (const auto& line : input) commands.push_back(parseCommand(line));

  return commands;
}

int executeCommands(const std::vector<Command>& commands, Registers& registers) {
  int highestRegisterValue{std::numeric_limits<int>::min()};

  for (const auto& command : commands) {
    executeCommand(command, registers);
    auto val = getMaximalRegisterValue(registers);
    if (val > highestRegisterValue) highestRegisterValue = val;
  }

  return highestRegisterValue;
}

void executeCommand(const Command& command, Registers& registers) {
  if (!isConditionFulfilled(command._condition, registers)) return;
  executeInstruction(command._instruction, registers);
}

bool isConditionFulfilled(const Condition& condition, Registers& registers) {
  switch (condition._type) {
    case Condition::Type::GREATER:
      return registers[condition._registerName] > condition._value;
    case Condition::Type::GREATER_OR_EQUAL:
      return registers[condition._registerName] >= condition._value;
    case Condition::Type::EQUAL:
      return registers[condition._registerName] == condition._value;
    case Condition::Type::LESS_OR_EQUAL:
      return registers[condition._registerName] <= condition._value;
    case Condition::Type::LESS:
      return registers[condition._registerName] < condition._value;
    case Condition::Type::NOT_EQUAL:
      return registers[condition._registerName] != condition._value;
  }

  return false;
}

void executeInstruction(const Instruction& instruction, Registers& registers) {
  switch (instruction._type) {
    case Instruction::Type::INC:
      registers[instruction._registerName] += instruction._value;
      break;
    case Instruction::Type::DEC:
      registers[instruction._registerName] -= instruction._value;
      break;
  }
}

int getMaximalRegisterValue(const Registers& registers) {
  if (registers.empty()) return 0;

  auto hasBiggerValue = [](const auto& n1, const auto& n2) { return n1.second < n2.second; };

  auto it = std::max_element(registers.begin(), registers.end(), hasBiggerValue);
  return it->second;
}