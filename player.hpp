#pragma once

#include "position.hpp"

#include <string>

class Player {
  std::string name;
  int coins, level;
  double speed;
  Position position;

public:
  Player(std::string name = "default");

  void levelUp();
  void step(Position position);
  void teleport(Position position);

  auto getLevel() -> int;
  auto getName() -> std::string;
  auto getPosition() -> Position;
};
