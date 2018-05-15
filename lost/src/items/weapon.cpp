#include "weapon.h"

weapon::weapon(json j) : item(j) {
  weapon_type       = j["weapon_type"];
  attack_rate       = j["attack_rate"];
  damage            = j["damage"];
  accuracy          = j["accuracy"];
  magazine_capacity = j["magazine_capacity"];
  ammo_capacity     = j["ammo_capacity"];
  reload_time       = j["reload_time"];
  effective_range   = j["effective_range"];
  recoil            = j["recoil"];
  impact            = j["impact"];
  attack_range      = j["attack_range"];
}

weapon::weapon(json j, double dmg) : item(j) {
  weapon_type       = j["weapon_type"];
  attack_rate       = j["attack_rate"];
  damage            = dmg;
  accuracy          = j["accuracy"];
  magazine_capacity = j["magazine_capacity"];
  ammo_capacity     = j["ammo_capacity"];
  reload_time       = j["reload_time"];
  effective_range   = j["effective_range"];
  recoil            = j["recoil"];
  impact            = j["impact"];
  attack_range      = j["attack_range"];
}

weapon::~weapon() {}
