#include "player.hpp"

#include <cmath>

Player::Player(std::string name) : name(name), level(1), coins(0), x(0.0), y(0.0), speed(4) {
}

void Player::levelUp() {
  ++this->level;
}

void Player::step(double x, double y) {
  double xlen = x - this->x,
         ylen = y - this->y,
         length = std::sqrt(std::abs(std::pow(xlen, 2) + std::pow(ylen, 2)));

  this->teleport((xlen / length) * this->speed,
                 (ylen / length) * this->speed);
}

void Player::teleport(double x, double y) {
  this->x = x;
  this->y = y;
}

auto Player::getLevel() -> int {
  return this->level;
}

auto Player::getName() -> std::string {
  return this->name;
}

auto Player::getX() -> double {
  return this->x;
}

auto Player::getY() -> double {
  return this->y;
}
