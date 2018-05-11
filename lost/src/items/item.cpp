#include "item.h"

item::item(json j) {
  name      = j["name"];
  rarity    = j["rarity"];
  item_type = j["item_type"];
}

item::~item() {}
