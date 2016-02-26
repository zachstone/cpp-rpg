#pragma once

#include <string>

#include "Position.hpp"

class Item {
  std::string name;
  int value;
  Position position;

public:
  Item(std::string name = "Generic Item", int value = 0, Position position = Position{0.0, 0.0});

  auto getName() -> std::string;
};
