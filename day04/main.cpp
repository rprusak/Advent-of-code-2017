#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

#include "common.h"

template <typename Map>
bool map_compare(Map const& lhs, Map const& rhs) {
    return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool isPasswordValid(const std::string& password) {
    std::stringstream stream{password};
    std::set<std::string> words;
    std::string word;

    while (stream && stream >> word) {
        if (words.count(word) > 0) return false;

        words.insert(word);
    }

    return true;
}

bool isAnagram(const std::string& firstWord, const std::string& secondWord) {
    std::map<char, unsigned> firstWordHistogram{};
    for (auto c : firstWord) {
        firstWordHistogram[c]++;
    }

    std::map<char, unsigned> secondWordHistogram{};
    for (auto c : secondWord) {
        secondWordHistogram[c]++;
    }

    return map_compare(firstWordHistogram, secondWordHistogram);
}

bool isPasswordValid2(const std::string& password) {
    std::stringstream stream{password};
    std::set<std::string> words;
    std::string word;

    auto hasAnagramWord = [&word](const std::string& s) { return isAnagram(word, s); };

    while (stream && stream >> word) {
        if (words.count(word) > 0) return false;
        if (std::find_if(words.begin(), words.end(), hasAnagramWord) != words.end()) return false;

        words.insert(word);
    }

    return true;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Invalid arguments" << std::endl;
        exit(EXIT_FAILURE);
    }

    unsigned validPasswordCounter{0};
    auto input = common::readInput(argv[1]);
    for (const auto& line : input) {
        if (isPasswordValid(line)) validPasswordCounter++;
    }

    std::cout << validPasswordCounter << std::endl;

    validPasswordCounter = 0;
    for (const auto& line : input) {
        if (isPasswordValid2(line)) validPasswordCounter++;
    }

    std::cout << validPasswordCounter << std::endl;

    return 0;
}
