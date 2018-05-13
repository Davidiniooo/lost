#pragma once

#include "SFML/Graphics.hpp"
#include "lost.h"

class item {
public:
  item() : name("none"), texture(nullptr), rarity(RARITY_COMMON), item_type(ITEM_TYPE_COLLECTABLE) {}
  item(json j);
  item(std::string n, sf::Texture *t, e_rarity r, e_item_type i)
      : name(n), texture(t), rarity(r), item_type(i) {}
  ~item();

  std::string  name;
  sf::Texture *texture;
  e_rarity     rarity;
  e_item_type  item_type;
};

std::string get_item_path_from_name(std::string name);
