#ifndef DAY13_DAY13_H
#define DAY13_DAY13_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace day13 {
class Layer {
public:
  Layer(unsigned long id, unsigned long depth);

  void moveScanner();
  bool isPacketFound() const;
  unsigned long getSeverity() const;

  bool isDelayAllowed(unsigned long delay) const;

  unsigned long getId() const;
  unsigned long getDepth() const;

private:
  enum class SCANNER_DIRECTION { UP, DOWN };

  SCANNER_DIRECTION _scannerDirection{SCANNER_DIRECTION::UP};
  unsigned long _scannerPosition{1};

  unsigned long _id;
  unsigned long _depth;

  unsigned long _period;
  unsigned long _start;
};

std::ostream& operator<<(std::ostream& output, const day13::Layer& layer);

std::vector<Layer> parseLayers(const std::vector<std::string>& input);
unsigned long partOne(const std::vector<std::string>& input);

bool canPassWithDelay(const std::vector<Layer>& layers, unsigned long delay);
unsigned long partTwo(const std::vector<std::string>& input);

}  // namespace day13

#endif