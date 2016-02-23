#include <iostream>

#include "player.hpp"

auto main() -> int {
  Player player = Player();
  player.levelUp();
  std::cout << player.getLevel() << std::endl
            << player.getName();

  return 0;
}
