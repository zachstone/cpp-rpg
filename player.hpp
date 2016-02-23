#include <string>

class Player {
  std::string name;
  int coins;
  int level;

public:
  Player(std::string name = "default");
  void levelUp();

  auto getLevel() -> int;
  auto getName() -> std::string;
};
