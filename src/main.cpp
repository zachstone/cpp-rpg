#include <iostream>

#include "player.hpp"
//#include "item.hpp"

auto main() -> int {
  Player player = Player();
  Item item = Item("Magic Boots", 274, Position{78.3, 23.9});
  player.levelUp();
  player.addItem(item);

  std::cout << player.getLevel()
            << std::endl
            << player.getName()
            << std::endl;

  player.step(Position{10.0, 5.0});
  std::cout << player.getPosition().x << std::endl
            << player.getPosition().y << std::endl;

  std::cout << player.printInventory() << std::endl;
  return 0;
}
