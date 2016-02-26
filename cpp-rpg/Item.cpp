#include "Item.hpp"

Item::Item(std::string name, int value, Position position) : name(name), value(value), position(position) {
}

auto Item::getName() -> std::string {
  return this->name;
}
