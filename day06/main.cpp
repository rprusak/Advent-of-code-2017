#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

std::string getConfiguration(std::vector<int>& blocks) {
    std::stringstream s;

    for (auto block : blocks)
        s << block;

    return s.str();
}

void performShuffle(std::vector<int>& blocks) {
    auto maxIt = std::max_element(blocks.begin(), blocks.end());
    auto blockValue = *maxIt;
    *maxIt = 0;

    while (blockValue > 0) {
        maxIt++;
        if (maxIt == blocks.end())
            maxIt = blocks.begin();

        (*maxIt)++;
        blockValue--;
    }
}

unsigned shuffle(std::vector<int>& blocks) {
    std::set<std::string> seenConfigurations;
    unsigned shuffleCount{0};

    while(true) {
        auto configuration = getConfiguration(blocks);
        if (seenConfigurations.count(configuration) > 0) {
            break;
        }

        seenConfigurations.insert(configuration);
        shuffleCount++;
        performShuffle(blocks);
    }

    return shuffleCount;
}

unsigned shuffle2(std::vector<int>& blocks) {
    std::map<std::string, unsigned> seenConfigurations;
    unsigned shuffleCount{0};

    while(true) {
        auto configuration = getConfiguration(blocks);
        if (seenConfigurations.count(configuration) > 0) {
            return shuffleCount - seenConfigurations[configuration];
        }

        seenConfigurations[configuration] = shuffleCount;
        shuffleCount++;
        performShuffle(blocks);
    }
}

int main() {
    std::vector<int> v{4, 1, 15, 12, 0, 9, 9, 5, 5, 8, 7, 3, 14, 5, 12, 3};
    std::cout << shuffle(v) << std::endl;

    std::vector<int> v2{2, 4, 1, 2};
    std::cout << shuffle2(v) << std::endl;

    return 0;
}
