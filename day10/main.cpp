#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

template <typename T>
class Hash {
public:
  unsigned calculate(std::vector<T>& buffer, const std::vector<T>& lengths) {
    for (auto length : lengths) {
      std::vector<unsigned> tmp;
      tmp.reserve(length);

      for (size_t i = 0; i < length; i++) {
        size_t index = (i + _currentPosition) % buffer.size();
        tmp.push_back(buffer[index]);
      }

      std::reverse(tmp.begin(), tmp.end());

      for (size_t i = 0; i < length; i++) {
        size_t index = (i + _currentPosition) % buffer.size();
        buffer[index] = tmp[i];
      }

      _currentPosition = (_currentPosition + _skipSize + length) % buffer.size();
      _skipSize++;
    }

    return buffer[0] * buffer[1];
  }

  std::vector<T> generateBuffer(size_t bufferSize) {
    std::vector<T> buffer(bufferSize);
    std::iota(buffer.begin(), buffer.end(), 0);
    return buffer;
  }

private:
  typename std::vector<T>::size_type _currentPosition{0};
  typename std::vector<T>::size_type _skipSize{0};
};

void partOne() {
  std::vector<unsigned> lengths{76,  1,   88, 148, 166, 217, 130, 0,
                                128, 254, 16, 2,   130, 71,  255, 229};
  Hash<unsigned> hash;
  auto buffer = hash.generateBuffer(256);

  std::cout << "Part 1: " << hash.calculate(buffer, lengths) << std::endl;
}

std::vector<unsigned char> prepareInputLengths(const std::string& input) {
  std::vector<unsigned char> result;

  std::copy(input.begin(), input.end(), std::back_inserter(result));
  const std::vector<unsigned char> additionalValues{17, 31, 73, 47, 23};
  std::copy(additionalValues.begin(), additionalValues.end(), std::back_inserter(result));

  return result;
}

template <typename I>
std::string n2hexstr(I w, size_t hex_len = sizeof(I) << 1) {
  static const char* digits = "0123456789abcdef";
  std::string rc(hex_len, '0');
  for (size_t i = 0, j = (hex_len - 1) * 4; i < hex_len; ++i, j -= 4)
    rc[i] = digits[(w >> j) & 0x0f];
  return rc;
}

void partTwo() {
  auto input = prepareInputLengths("76,1,88,148,166,217,130,0,128,254,16,2,130,71,255,229");

  Hash<unsigned char> hash;
  auto buffer = hash.generateBuffer(256);
  for (size_t i = 0; i < 64; i++) {
    hash.calculate(buffer, input);
  }

  std::vector<unsigned char> denseHash(16);
  for (size_t i = 0; i < 16; i++) {
    unsigned char xorValue{buffer[16 * i]};
    for (size_t j = i * 16 + 1; j < (i + 1) * 16; j++) {
      xorValue ^= buffer[j];
    }

    denseHash[i] = xorValue;
  }

  std::cout << "Part 2: ";
  for (size_t i = 0; i < 16; i++) {
    auto finalHash = n2hexstr(denseHash[i]);
    std::cout << finalHash;
  }
  std::cout << std::endl;
}

int main() {
  partOne();
  partTwo();

  return 0;
}
