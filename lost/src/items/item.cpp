#include "item.h"
#include "SDL2/SDL.h"
#include "gfx/texture_loader.h"
#include "core/game.h"

item::item(json j) {
  name      = j["name"];
  rarity    = j["rarity"];
  item_type = j["item_type"];
  texture = get_texture(j["texture"], global_game->renderer);
}

item::~item() {}
