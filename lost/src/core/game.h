#pragma once

#include "SFML/Graphics.hpp"
#include "lost.h"

namespace lost::worlds {
class world;
}

namespace lost::core {

using namespace lost;

class game {
public:
  game(uint w, uint h);
  ~game();

  int run(double fps);
  int clean();

  UPDATE_RENDER

  bool                 running;
  sf::RenderWindow     window;
  lost::worlds::world *current_world;
};

} // namespace lost::core
