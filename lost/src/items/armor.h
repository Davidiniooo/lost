#pragma once

#include "item.h"

class armor : public item {
public:
  armor(json j);
  ~armor();

  e_armor_type armor_type;
  double       protection;
};