#include "item.h"
#include "core/game.h"
#include "gfx/texture_loader.h"
#include <algorithm>

namespace lost::items {

item::item(json j) {
  name      = (std::string)j["name"];
  rarity    = j["rarity"];
  item_type = j["item_type"];
  texture   = get_texture(j["texture"]);
}

item::~item() {}

std::string get_item_path_from_name(std::string name) {
  std::string tmp = name;
  std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
  std::replace(tmp.begin(), tmp.end(), ' ', '_');
  return "items/" + tmp + ".json";
}

} // namespace lost::items
