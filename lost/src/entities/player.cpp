#include "player.h"

namespace lost::entities {

player::player() {}

player::player(json j) {
  name   = (std::string)j["name"];
  race   = j["race"];
  gender = j["gender"];
  inv    = items::player_inventory(j["inventory"]);
}

player::~player() {}

int player::update(double dt) {
  double _dt = dt;
  _dt += 1;
  return 0;
}

int player::render() {
  return 0;
}

} // namespace lost::entities
