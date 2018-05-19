#pragma once

#include "item.h"

namespace lost::items {

class armor : public item {
public:
  armor(json j);
  armor() : item() {}
  ~armor();

  data::e_armor_type armor_type;
  double             protection;
};

} // namespace lost::items
