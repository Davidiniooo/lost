#pragma once

#include "entity.h"
#include "lost.h"

namespace lost::entities {

class npc : public entity {
public:
  npc(json j);
  ~npc();

  UPDATE_RENDER

  std::string    name;
  data::e_race   race;
  data::e_gender gender;
};

} // namespace lost::entities
