#pragma once

#include"lost.h"

namespace lost::entities {
  class game_entity;
}

namespace lost::scripting {
  using namespace lost;

  int execute_script(std::string path);
  int execute_script(std::string path, lost::entities::game_entity* e);
}
