#include "day13.h"

#include <algorithm>

#include "common.h"

namespace day13 {
Layer::Layer(unsigned long id, unsigned long depth) : _id(id), _depth(depth) {
  _period = 2 * (_depth - 1);

  auto tmp = 0ul;

  while (_id > tmp) tmp += _period;

  _start = tmp - _id;
}

unsigned long Layer::getId() const { return _id; }

unsigned long Layer::getDepth() const { return _depth; }

void Layer::moveScanner() {
  if (_scannerPosition == 1 && _scannerDirection == SCANNER_DIRECTION::DOWN) {
    _scannerPosition++;
    _scannerDirection = SCANNER_DIRECTION::UP;
  } else if (_scannerPosition == _depth && _scannerDirection == SCANNER_DIRECTION::UP) {
    _scannerPosition--;
    _scannerDirection = SCANNER_DIRECTION::DOWN;
  } else if (_scannerDirection == SCANNER_DIRECTION::UP) {
    _scannerPosition++;
  } else {
    _scannerPosition--;
  }
}

bool Layer::isPacketFound() const { return _scannerPosition == 1; }

unsigned long Layer::getSeverity() const { return _id * _depth; }

bool Layer::isDelayAllowed(unsigned long delay) const { return (delay - _start) % _period != 0; }

std::vector<Layer> parseLayers(const std::vector<std::string>& input) {
  std::vector<Layer> layers;

  for (const auto& entry : input) {
    auto split = common::split(entry, ":");
    Layer layer{std::stoul(split[0]), std::stoul(split[1])};
    layers.push_back(layer);
  }

  return layers;
}

Layer& getLayerWithId(std::vector<Layer>& layers, unsigned long id) {
  auto layerHasThisId = [id](const Layer& layer) { return layer.getId() == id; };
  auto it = std::find_if(layers.begin(), layers.end(), layerHasThisId);
  return *it;
}

bool layerWithIdExists(const std::vector<Layer>& layers, unsigned long id) {
  auto layerHasThisId = [id](const Layer& layer) { return layer.getId() == id; };
  auto it = std::find_if(layers.begin(), layers.end(), layerHasThisId);
  return it != layers.end();
}

void moveScanner(std::vector<Layer>& layers) {
  for (auto& layer : layers) layer.moveScanner();
}

unsigned long calculateSeverity(std::vector<Layer> layers) {
  unsigned long severity{0};
  auto lastLayerId = layers.back().getId();

  for (unsigned long layerId = 0; layerId <= lastLayerId; layerId++) {
    if (layerWithIdExists(layers, layerId)) {
      const auto& currentLayer = getLayerWithId(layers, layerId);
      if (currentLayer.isPacketFound()) severity += currentLayer.getSeverity();
    }

    moveScanner(layers);
  }

  return severity;
}

unsigned long partOne(const std::vector<std::string>& input) {
  auto layers = parseLayers(input);
  return calculateSeverity(layers);
}

bool canPassWithDelay(const std::vector<Layer>& layers, unsigned long delay) {
  for (const auto& layer : layers)
    if (!layer.isDelayAllowed(delay)) return false;

  return true;
}

unsigned long partTwo(const std::vector<std::string>& input) {
  auto layers = parseLayers(input);

  unsigned long delay{0};
  while (!canPassWithDelay(layers, delay)) delay++;

  return delay;
}
}  // namespace day13
