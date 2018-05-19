#include "npc.h"

namespace lost::entities {

npc::npc(json j) {
  name   = (std::string)j["name"];
  race   = j["race"];
  gender = j["gender"];
}

npc::~npc() {}

int npc::update(double dt) {
  double _dt = dt;
  _dt += 1;
  return 0;
}

int npc::render() {
  return 0;
}

} // namespace lost::entities
