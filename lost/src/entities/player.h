#pragma once

#include "entity.h"
#include "items/player_inventory.h"
#include "lost.h"

class player : entity {
public:
  player();
  player(json j);
  ~player();

  UPDATE_RENDER

  std::string      name;
  e_race           race;
  e_gender         gender;
  player_inventory inv;
};
