#include "player.hpp"

/*Player::Player() {
  this("default");
}*/

Player::Player(std::string name) : name(name), level(1), coins(0) {
}

void Player::levelUp() {
  ++(this->level);
}

auto Player::getLevel() -> int {
  return this->level;
}

auto Player::getName() -> std::string {
  return this->name;
}
