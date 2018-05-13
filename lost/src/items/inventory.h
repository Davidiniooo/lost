#pragma once

#include "item.h"

struct inventory_item {
  item i;
  uint count;
};

class inventory {
public:
  inventory();
  ~inventory();

  std::vector<inventory_item> items;
};
