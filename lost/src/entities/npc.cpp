#include "npc.h"

namespace lost::entities {

npc::npc(json j) {
  name   = (std::string)j["name"];
  race   = j["race"];
  gender = j["gender"];
  update = j["update"];
  render = j["render"];
}

npc::~npc() {}

} // namespace lost::entities
