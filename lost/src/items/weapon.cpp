#include "weapon.h"

namespace lost::items {

weapon::weapon(json j) : item(j) {
  weapon_type = j["weapon_type"];
  attack_rate = j["attack_rate"];
  damage      = j["damage"];
  level       = 1;
  max_level   = j["max_level"];
  upgrades    = j["upgrades"];
  if (weapon_type & 0b10000) {
    attack_range = j["attack_range"];
  } else {
    accuracy          = j["accuracy"];
    magazine_capacity = j["magazine_capacity"];
    ammo_capacity     = j["ammo_capacity"];
    reload_time       = j["reload_time"];
    effective_range   = j["effective_range"];
    recoil            = j["recoil"];
    impact            = j["impact"];
  }
}

weapon::weapon(json j, uint lvl) : item(j) {
  weapon_type = j["weapon_type"];
  attack_rate = j["attack_rate"];
  damage      = j["damage"];
  level       = lvl;
  max_level   = j["max_level"];
  upgrades    = j["upgrades"];
  if (weapon_type & 0b10000) {
    attack_range = j["attack_range"];
  } else {
    accuracy          = j["accuracy"];
    magazine_capacity = j["magazine_capacity"];
    ammo_capacity     = j["ammo_capacity"];
    reload_time       = j["reload_time"];
    effective_range   = j["effective_range"];
    recoil            = j["recoil"];
    impact            = j["impact"];
  }
}

weapon::~weapon() {}

} // namespace lost::items
