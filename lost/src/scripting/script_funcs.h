#include <lua5.3/lua.hpp>
#include "lost.h"
#include "core/game.h"
#include "worlds/layers/tile_layer.h"
#include "worlds/world.h"

namespace lost::scripting::funcs {
  using namespace lost;

  int get_tile_layer(lua_State* L) {
    std::string name = lua_tostring(L, 1);

    for (uint i = 0; i < g_game->m_current_world->m_layers.size(); ++i) {
      if (g_game->m_current_world->m_layers[i]->name.compare(name) == 0) {
        lua_pushlightuserdata(L, (worlds::layers::tile_layer*)(g_game->m_current_world->m_layers[i]));
        return 1;
      }
    }

    return 0;
  }
}