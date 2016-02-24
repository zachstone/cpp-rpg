#include <iostream>

#include "player.hpp"

auto main() -> int {
  Player player = Player();
  player.levelUp();
  std::cout << player.getLevel()
            << std::endl
            << player.getName()
            << std::endl;

  player.step(Position{10.0, 5.0});
  std::cout << player.getPosition().x
            << std::endl
            << player.getPosition().y;
  return 0;
}
