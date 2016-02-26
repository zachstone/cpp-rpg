#pragma once

#include <string>
#include <vector>

#include "Position.hpp"
#include "Item.hpp"

class Player {
  std::string name;
  int coins, level;
  double speed;
  Position position;
  std::vector<Item> inventory;

public:
  Player(std::string name = "default");

  void levelUp();
  void step(Position position);
  void teleport(Position position);
  void addItem(Item item);

  auto getLevel() -> int;
  auto getName() -> std::string;
  auto getPosition() -> Position;
  auto printInventory() -> std::string;
};
