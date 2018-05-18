#include "weapon.h"

weapon::weapon(json j) : item(j) {
  weapon_type = j["weapon_type"];
  attack_rate = j["attack_rate"];
  damage      = j["damage"];
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

weapon::weapon(json j, double dps) : item(j) {
  weapon_type = j["weapon_type"];
  attack_rate = j["attack_rate"];
  damage      = dps / attack_range;
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
