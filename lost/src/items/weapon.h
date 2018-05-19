#pragma once

#include "item.h"

namespace lost::items {

class weapon : public item {
public:
  weapon(json j, double dps);
  weapon(json j);
  weapon() : item() {}
  ~weapon();

  data::e_weapon_type weapon_type;       // all
  double              attack_rate;       // all
  double              damage;            // all
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
