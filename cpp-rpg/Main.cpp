#include <iostream>

#include "SFML/Graphics.hpp"

#include "Player.hpp"
#include "Rational.hpp"
#include "Item.hpp"

auto main() -> int {
  sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");

  window.display();
  return 0;
}

void cmd_output() {
  Player player = Player();
  Item item = Item("Magic Boots", 274, Position{ 78.3, 23.9 });
  player.levelUp();
  player.addItem(item);

  std::cout << player.getLevel()
            << std::endl
            << player.getName()
            << std::endl;

  player.step(Position{ 10.0, 5.0 });
  std::cout << player.getPosition().x << std::endl
            << player.getPosition().y << std::endl;

  std::cout << player.printInventory() << std::endl;

  auto p = rat64_t(1, 2);
  p += 5;
  std::cout << p.a() << " " << p.b() << std::endl;
}
