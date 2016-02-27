#include "Player.hpp"

#include <cmath>

Player::Player(std::string name) : name(name), level(1), coins(0), position{0.0, 0.0}, speed(4) {
}

void Player::levelUp() {
  ++this->level;
}

void Player::step(Position target) {
  double xlen = target.x - position.x,
         ylen = target.y - position.y,
         length = std::sqrt(std::abs(std::pow(xlen, 2) + std::pow(ylen, 2)));

  teleport(Position{(xlen / length) * this->speed,
					(ylen / length) * this->speed});
}

void Player::teleport(Position target) {
  position = target;
}

void Player::addItem(Item item) {
  inventory.push_back(item);
}

auto Player::printInventory() -> std::string {
  return inventory.front().getName();
}

auto Player::getLevel() -> int {
  return level;
}

auto Player::getName() -> std::string {
  return name;
}

auto Player::getPosition() -> Position {
  return position;
}
