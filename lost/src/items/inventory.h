#pragma once

#include "item.h"

namespace lost::items {

struct inventory_item {
  inventory_item() {}
  inventory_item(item it, uint c) : i(it), count(c) {}
  item i;
  uint count;
};

class inventory {
public:
  inventory();
  inventory(json j);
  ~inventory();

  std::vector<inventory_item> items;
};

}
