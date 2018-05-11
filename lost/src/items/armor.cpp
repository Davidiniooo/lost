#include "armor.h"

armor::armor(json j) : item(j) {
  armor_type = j["armor_type"];
  protection = j["protection"];
}

armor::~armor() {}
