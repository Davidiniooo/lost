#include "player.h"

player::player() {}

player::player(json j) {
  name = j["name"];
  race = j["race"];
  gender = j["gender"];
  inv = player_inventory(j["inventory"]);
}

player::~player() {}

int player::update(double dt) {
  return 0;
}

int player::render() {
  return 0;
}
