#pragma once

#include "entity.h"
#include "items/player_inventory.h"
#include "lost.h"

namespace lost::entities {

class player : public entity {
public:
  player();
  player(json j);
  ~player();

  UPDATE_RENDER

  std::string             name;
  data::e_race            race;
  data::e_gender          gender;
  items::player_inventory inv;
};

} // namespace lost::entities
