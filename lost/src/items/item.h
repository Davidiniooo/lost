#pragma once

#include "lost.h"

struct SDL_Texture;

class item {
public:
  item(json j);
  ~item();

  std::string name;
  SDL_Texture * texture;
  e_rarity    rarity;
  e_item_type item_type;
};
