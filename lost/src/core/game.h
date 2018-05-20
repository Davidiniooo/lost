#pragma once

#include "SFML/Graphics.hpp"
#include "input/input_manager.h"
#include "lost.h"
#include "worlds/layers/tile_layer.h"

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

  bool                             m_running;
  sf::RenderWindow                 m_window;
  lost::worlds::world *            m_current_world;
  lost::input::input_manager       m_input_manager;
  lost::worlds::layers::tile_layer t;
};

} // namespace lost::core
