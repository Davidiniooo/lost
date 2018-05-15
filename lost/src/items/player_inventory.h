#pragma once

#include "armor.h"
#include "inventory.h"
#include "weapon.h"

class player_inventory : public inventory {
public:
  player_inventory();
  player_inventory(json j);
  ~player_inventory();

  armor head;
  armor arms;
  armor chest;
  armor legs;

  weapon primary;
  weapon secondary;
  weapon ternary;
};
