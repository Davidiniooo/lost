#include "scripting/cpp_get_tile_layer.h"

namespace lost::scripting::funcs {
lost::worlds::layers::tile_layer *cpp_get_tile_layer(std::string name) {
  for (uint i = 0; i < lost::g_game->m_current_world->m_layers.size(); ++i) {
    if (lost::g_game->m_current_world->m_layers[i]->name.compare(name) == 0) {
      return (lost::worlds::layers::tile_layer *)(lost::g_game->m_current_world
                                                      ->m_layers[i]);
    }
  }

  return nullptr;
}
}