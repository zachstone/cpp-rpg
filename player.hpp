#include <string>

class Player {
  std::string name;
  int coins, level;
  double x, y, speed;

public:
  Player(std::string name = "default");

  void levelUp();
  void step(double x, double y);
  void teleport(double x, double y);

  auto getLevel() -> int;
  auto getName() -> std::string;
  auto getX() -> double;
  auto getY() -> double;
};
