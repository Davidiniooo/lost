#pragma once

#include "entity.h"
#include "lost.h"

class npc : public entity {
public:
  npc(json j);
  ~npc();

  std::string name;
  e_race      race;
  e_gender    gender;
};