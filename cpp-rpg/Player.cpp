#include "Player.hpp"

#include <cmath>

Player::Player(std::string name) : name(name), level(1), coins(0), position{0.0, 0.0}, speed(4) {
}

void Player::levelUp() {
  ++this->level;
}

void Player::step(Position position) {
  double xlen = position.x - this->position.x,
         ylen = position.y - this->position.y,
         length = std::sqrt(std::abs(std::pow(xlen, 2) + std::pow(ylen, 2)));

  this->teleport(Position{(xlen / length) * this->speed,
                          (ylen / length) * this->speed});
}

void Player::teleport(Position position) {
  this->position = position;
}

void Player::addItem(Item item) {
  this->inventory.push_back(item);
}

auto Player::printInventory() -> std::string {
  return this->inventory.front().getName();
}

auto Player::getLevel() -> int {
  return this->level;
}

auto Player::getName() -> std::string {
  return this->name;
}

auto Player::getPosition() -> Position {
  return this->position;
}
