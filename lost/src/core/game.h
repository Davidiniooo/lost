#pragma once

#include "SFML/Graphics.hpp"
#include "lost.h"

namespace lost {
  
class world;

class game {
public:
  game();
  ~game();

  int run(uint w, uint h, double fps);
  int clean();

  UPDATE_RENDER

  bool             running;
  sf::RenderWindow window;
  world *          current_world;
};

} // namespace lost
