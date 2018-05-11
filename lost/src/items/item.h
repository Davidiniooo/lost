#pragma once

#include "lost.h"

class item {
public:
  item(json j);
  ~item();

  std::string name;
  e_rarity    rarity;
  e_item_type item_type;
};
