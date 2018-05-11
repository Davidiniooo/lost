#pragma once

#include "item.h"

class weapon : public item {
public:
  weapon(json j);
  ~weapon();

  e_weapon_type weapon_type;       // all
  double        attack_rate;       // all
  double        damage;            // all
  double        accuracy;          // ranged
  uint          magazine_capacity; // ranged
  uint          ammo_capacity;     // ranged
  double        reload_time;       // ranged
  double        effective_range;   // ranged
  double        recoil;            // ranged
  double        impact;            // ranged
  double        attack_range;      // melee
};
