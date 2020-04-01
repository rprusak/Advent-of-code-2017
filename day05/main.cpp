#include <iostream>
#include <vector>

#include "common.h"

unsigned performSteps2(std::vector<int> jumps) {
    int index{0};
    unsigned steps{0};

    while (index >= 0 && index < jumps.size()) {
        int offset = jumps[index];
        if (offset >= 3)
            jumps[index]--;
        else
            jumps[index]++;

        index += offset;
        steps++;
    }

    return steps;
}

unsigned performSteps(std::vector<int> jumps) {
    int index{0};
    unsigned steps{0};

    while (index >= 0 && index < jumps.size()) {
        int offset = jumps[index];
        jumps[index]++;
        index += offset;
        steps++;
    }

    return steps;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Invalid arguments" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<int> values{};
    auto input = common::readInput(argv[1]);
    for (const auto& line : input) {
        values.push_back(std::stoi(line));
    }

    std::cout << performSteps(values) << std::endl;
    std::cout << performSteps2(values) << std::endl;

    return 0;
}
