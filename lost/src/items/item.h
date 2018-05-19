#pragma once

#include "SFML/Graphics.hpp"
#include "lost.h"

namespace lost::items {

using namespace lost;

class item {
public:
  item()
      : name("none"), texture(nullptr), rarity(data::RARITY_COMMON),
        item_type(data::ITEM_TYPE_COLLECTABLE) {}
  item(json j);
  item(std::string n, sf::Texture *t, data::e_rarity r, data::e_item_type i)
      : name(n), texture(t), rarity(r), item_type(i) {}
  ~item();

  std::string       name;
  sf::Texture *     texture;
  data::e_rarity    rarity;
  data::e_item_type item_type;
};

std::string get_item_path_from_name(std::string name);

} // namespace lost::items
