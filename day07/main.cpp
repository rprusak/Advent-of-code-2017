#include <iostream>
#include <regex>
#include <set>
#include <string>
#include <vector>

#include "common.h"

struct Program {
    std::string name;
    unsigned weight;
    std::vector<std::string> childPrograms;
};

Program parseLine(const std::string& str) {
    static std::regex pattern{R"#(^(\w+)\s\((\d+)\)((\s->\s(.+))?)$)#"};

    std::smatch results;
    if (!std::regex_match(str, results, pattern))
        throw std::runtime_error("Could not match line: " + str);

    Program p;
    p.name = results.str(1);
    p.weight = std::stoul(results.str(2));
    p.childPrograms = common::split(results.str(5), ",");

    return p;
}

std::vector<Program> parseInput(const std::vector<std::string>& input) {
    std::vector<Program> programs;

    for (const auto& line : input) {
        programs.push_back(parseLine(line));
    }

    return programs;
}

std::string getRootProgram(const std::vector<Program>& programs) {
    std::set<std::string> programsWithParent;

    for (const auto& program : programs) {
        for (const auto& child : program.childPrograms) {
            programsWithParent.insert(child);
        }
    }

    auto hasNoParent = [&programsWithParent](const Program& p) {
        return programsWithParent.count(p.name) == 0;
    };

    auto it = std::find_if(programs.begin(), programs.end(), hasNoParent);
    return it->name;
}

std::map<std::string, const Program*> programsMap;

void buildMap(const std::vector<Program>& programs) {
    for (const auto& program : programs)
        programsMap[program.name] = &program;
}

unsigned getProgramWeight(const std::string& programName) {
    unsigned weight{0};

    const auto* program = programsMap[programName];

    for (const auto& childProgramName : program->childPrograms)
        weight += getProgramWeight(childProgramName);

    return weight + program->weight;
}

void part2(const std::vector<Program>& programs, const std::string& root) {
    buildMap(programs);

    for (const auto& childProgramName : programsMap[root]->childPrograms)
        std::cout << childProgramName << " " << getProgramWeight(childProgramName) << std::endl;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Invalid arguments!" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto input = common::readInput(argv[1]);
    auto programs = parseInput(input);
    auto root = getRootProgram(programs);
    std::cout << root << std::endl;

    part2(programs, "kzltfq");

    return 0;
}
