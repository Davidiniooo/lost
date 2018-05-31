#pragma once

#include "item.h"

namespace lost::items {

class weapon : public item {
public:
  weapon(json j, uint lvl);
  weapon(json j);
  weapon() : item() {}
  ~weapon();

  data::e_weapon_type weapon_type;       // all
  double              attack_rate;       // all
  double              damage;            // all
  uint                level;             // all
  uint                max_level;         // all
  json                upgrades;          // all
  double              accuracy;          // ranged
  uint                magazine_capacity; // ranged
  uint                ammo_capacity;     // ranged
  double              reload_time;       // ranged
  double              effective_range;   // ranged
  double              recoil;            // ranged
  double              impact;            // ranged
  double              attack_range;      // melee
};

} // namespace lost::items
