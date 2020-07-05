#ifndef DAY08_DAY08_H
#define DAY08_DAY08_H

#include <map>
#include <string>
#include <vector>

struct Condition {
  enum class Type { GREATER, GREATER_OR_EQUAL, EQUAL, LESS_OR_EQUAL, LESS, NOT_EQUAL };

  Type _type;
  std::string _registerName;
  int _value;
};

struct Instruction {
  enum class Type { INC, DEC };

  Type _type;
  std::string _registerName;
  int _value;
};

struct Command {
  Condition _condition;
  Instruction _instruction;
};

using Registers = std::map<std::string, int>;

Command parseCommand(const std::string& str);
std::vector<Command> parseInput(const std::vector<std::string>& input);
int executeCommands(const std::vector<Command>& commands, Registers& registers);
void executeCommand(const Command& command, Registers& registers);
bool isConditionFulfilled(const Condition& condition, Registers& registers);
void executeInstruction(const Instruction& instruction, Registers& registers);
int getMaximalRegisterValue(const Registers& registers);

#endif  // DAY08_DAY08_H
