#include "item.h"
#include "gfx/texture_loader.h"
#include "core/game.h"

item::item(json j) {
  name      = j["name"];
  rarity    = j["rarity"];
  item_type = j["item_type"];
  texture = get_texture(j["texture"]);
}

item::~item() {}
