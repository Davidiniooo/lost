#include "player.h"

namespace lost::entities {

player::player() {}

player::player(json j) {
  name   = (std::string)j["name"];
  race   = j["race"];
  gender = j["gender"];
  inv    = items::player_inventory(j["inventory"]);
  update = j["update"];
  render = j["render"];
}

player::~player() {}

} // namespace lost::entities
