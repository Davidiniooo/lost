#include "npc.h"

npc::npc(json j) {
  name   = j["name"];
  race   = j["race"];
  gender = j["gender"];
}

npc::~npc() {}

int npc::update(double dt) {
  return 0;
}

int npc::render() {
  return 0;
}