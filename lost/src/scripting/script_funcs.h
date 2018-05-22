#include <lua5.3/lua.hpp>
#include "lost.h"
#include "core/game.h"
#include "worlds/layers/tile_layer.h"
#include "worlds/world.h"

namespace lost::scripting::funcs {
  using namespace lost;

  int get_tile_layer(lua_State* L);

  int tile_layer_get_at(lua_State* L);

  int tile_layer_get_at_pixel(lua_State* L);

  int tile_layer_get_cell_x_at_pixel(lua_State* L);
  int tile_layer_get_cell_y_at_pixel(lua_State* L);

  int call_script(lua_State* L);
}